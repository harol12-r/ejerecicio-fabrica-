#include <stdio.h>
#include <string.h>

#define MAX 5

char nombres[MAX][30];
int minU[MAX], huevos[MAX], demandas[MAX];
float harina[MAX], agua[MAX], integral[MAX], azucar[MAX], sal[MAX];
int total = 0;

void iniciar();
void registrar();
void mostrar();
void pedirDemanda();
void editar();
void eliminar();
void evaluar();

int main() {
    int op;
    iniciar();

    do {
        printf("\n--- PANADERIA DOLCE ---\n");
        printf("1. Registrar producto\n2. Mostrar productos\n3. Decidir demanda\n");
        printf("4. Editar producto\n5. Eliminar producto\n6. Evaluar produccion\n7. Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: pedirDemanda(); break;
            case 4: editar(); break;
            case 5: eliminar(); break;
            case 6: evaluar(); break;
            case 7: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (op != 7);

    return 0;
}

void iniciar() {
    strcpy(nombres[0], "pan");
    minU[0] = 3; harina[0] = 120; agua[0] = 75; huevos[0] = 0; integral[0] = 0; azucar[0] = 4; sal[0] = 2.5; demandas[0] = 50;

    strcpy(nombres[1], "pan_integral");
    minU[1] = 4; harina[1] = 35; agua[1] = 85; huevos[1] = 0; integral[1] = 95; azucar[1] = 5; sal[1] = 2; demandas[1] = 40;

    strcpy(nombres[2], "pan_dulce");
    minU[2] = 5; harina[2] = 110; agua[2] = 40; huevos[2] = 1; integral[2] = 0; azucar[2] = 25; sal[2] = 1.5; demandas[2] = 35;

    total = 3;
}

void registrar() {
    if (total >= MAX) { printf("Maximo 5 productos.\n"); return; }
    while (getchar() != '\n');

    printf("Nombre: ");
    scanf("%s", nombres[total]);

    do { printf("Minutos por unidad: "); scanf("%d", &minU[total]); } while (minU[total] < 0);
    do { printf("Harina (g): "); scanf("%f", &harina[total]); } while (harina[total] < 0);
    do { printf("Agua (ml): "); scanf("%f", &agua[total]); } while (agua[total] < 0);
    do { printf("Huevos (und): "); scanf("%d", &huevos[total]); } while (huevos[total] < 0);
    do { printf("Harina integral (g): "); scanf("%f", &integral[total]); } while (integral[total] < 0);
    do { printf("Azucar (g): "); scanf("%f", &azucar[total]); } while (azucar[total] < 0);
    do { printf("Sal (g): "); scanf("%f", &sal[total]); } while (sal[total] < 0);
    do { printf("Demanda: "); scanf("%d", &demandas[total]); } while (demandas[total] < 0);

    total++;
    printf("Registrado.\n");
}

void mostrar() {
    if (total == 0) { printf("Sin productos.\n"); return; }
    printf("\n%-15s | %-7s | %-7s | %-7s | %-6s | %-7s | %-7s | %-6s | %-7s\n",
           "Producto", "Min/U", "Har(g)", "Agu(ml)", "Huv", "Int(g)", "Azu(g)", "Sal(g)", "Demanda");
    for (int i = 0; i < total; i++) {
        printf("%-15s | %-7d | %-7.1f | %-7.1f | %-6d | %-7.1f | %-7.1f | %-6.1f | %-7d\n",
               nombres[i], minU[i], harina[i], agua[i], huevos[i], integral[i], azucar[i], sal[i], demandas[i]);
    }
}

void pedirDemanda() {
    if (total == 0) { printf("Sin productos.\n"); return; }
    for (int i = 0; i < total; i++) {
        do {
            printf("Demanda de %s (actual %d): ", nombres[i], demandas[i]);
            scanf("%d", &demandas[i]);
        } while (demandas[i] < 0);
    }
    printf("Demanda actualizada.\n");
}

void editar() {
    if (total == 0) { printf("Sin productos.\n"); return; }
    while (getchar() != '\n');
    char bus[30];
    int pos = -1;

    printf("Nombre a editar: ");
    scanf("%s", bus);
    for (int i = 0; i < total; i++) {
        if (strcmp(nombres[i], bus) == 0) { pos = i; break; }
    }
    if (pos == -1) { printf("No encontrado.\n"); return; }

    printf("Nuevo nombre: "); scanf("%s", nombres[pos]);
    do { printf("Minutos por unidad: "); scanf("%d", &minU[pos]); } while (minU[pos] < 0);
    do { printf("Harina (g): "); scanf("%f", &harina[pos]); } while (harina[pos] < 0);
    do { printf("Agua (ml): "); scanf("%f", &agua[pos]); } while (agua[pos] < 0);
    do { printf("Huevos (und): "); scanf("%d", &huevos[pos]); } while (huevos[pos] < 0);
    do { printf("Harina integral (g): "); scanf("%f", &integral[pos]); } while (integral[pos] < 0);
    do { printf("Azucar (g): "); scanf("%f", &azucar[pos]); } while (azucar[pos] < 0);
    do { printf("Sal (g): "); scanf("%f", &sal[pos]); } while (sal[pos] < 0);
    do { printf("Demanda: "); scanf("%d", &demandas[pos]); } while (demandas[pos] < 0);
    printf("Editado.\n");
}

void eliminar() {
    if (total == 0) { printf("Sin productos.\n"); return; }
    while (getchar() != '\n');
    char bus[30];
    int pos = -1;

    printf("Nombre a eliminar: ");
    scanf("%s", bus);
    for (int i = 0; i < total; i++) {
        if (strcmp(nombres[i], bus) == 0) { pos = i; break; }
    }
    if (pos == -1) { printf("No encontrado.\n"); return; }

    for (int i = pos; i < total - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        minU[i] = minU[i + 1];
        harina[i] = harina[i + 1]; agua[i] = agua[i + 1];
        huevos[i] = huevos[i + 1]; integral[i] = integral[i + 1];
        azucar[i] = azucar[i + 1]; sal[i] = sal[i + 1];
        demandas[i] = demandas[i + 1];
    }
    total--;
    printf("Eliminado.\n");
}

void evaluar() {
    if (total == 0) { printf("Sin productos.\n"); return; }

    float minTot = 0, harTot = 0, aguTot = 0, huvTot = 0, intTot = 0, azuTot = 0, salTot = 0;
    for (int i = 0; i < total; i++) {
        minTot += minU[i] * demandas[i];
        harTot += harina[i] * demandas[i];
        aguTot += agua[i] * demandas[i];
        huvTot += huevos[i] * demandas[i];
        intTot += integral[i] * demandas[i];
        azuTot += azucar[i] * demandas[i];
        salTot += sal[i] * demandas[i];
    }

    float hDisp, harDisp, aguDisp, huvDisp, intDisp, azuDisp, salDisp;

    do { printf("Horas disponibles: "); scanf("%f", &hDisp); } while (hDisp < 0);
    do { printf("Harina disponible (g): "); scanf("%f", &harDisp); } while (harDisp < 0);
    do { printf("Agua disponible (ml): "); scanf("%f", &aguDisp); } while (aguDisp < 0);
    do { printf("Huevos disponibles (und): "); scanf("%f", &huvDisp); } while (huvDisp < 0);
    do { printf("Harina integral disponible (g): "); scanf("%f", &intDisp); } while (intDisp < 0);
    do { printf("Azucar disponible (g): "); scanf("%f", &azuDisp); } while (azuDisp < 0);
    do { printf("Sal disponible (g): "); scanf("%f", &salDisp); } while (salDisp < 0);

    float minDisp = hDisp * 60.0f;
    int hReq = (int)(minTot / 60);
    int mReq = (int)minTot % 60;

    printf("\nTiempo req: %dh %dmin | Disp: %.1f horas\n", hReq, mReq, hDisp);
    printf("Harina req: %.1f g | Disp: %.1f g\n", harTot, harDisp);
    printf("Agua req: %.1f ml | Disp: %.1f ml\n", aguTot, aguDisp);
    printf("Huevos req: %.0f | Disp: %.0f\n", huvTot, huvDisp);
    printf("Integral req: %.1f g | Disp: %.1f g\n", intTot, intDisp);
    printf("Azucar req: %.1f g | Disp: %.1f g\n", azuTot, azuDisp);
    printf("Sal req: %.1f g | Disp: %.1f g\n", salTot, salDisp);

    if (minTot <= minDisp && harTot <= harDisp && aguTot <= aguDisp &&
        huvTot <= huvDisp && intTot <= intDisp && azuTot <= azuDisp && salTot <= salDisp) {
        printf("SI puede cumplir con la demanda.\n");
    } else {
        printf("NO puede cumplir con la demanda:\n");
        if (minTot > minDisp) {
            float difMin = minTot - minDisp;
            printf("- Faltan %.0f minutos (%.2f horas)\n", difMin, difMin / 60.0f);
        }
        if (harTot > harDisp) printf("- Faltan %.1f g de harina\n", harTot - harDisp);
        if (aguTot > aguDisp) printf("- Faltan %.1f ml de agua\n", aguTot - aguDisp);
        if (huvTot > huvDisp) printf("- Faltan %.0f huevos\n", huvTot - huvDisp);
        if (intTot > intDisp) printf("- Faltan %.1f g de harina integral\n", intTot - intDisp);
        if (azuTot > azuDisp) printf("- Faltan %.1f g de azucar\n", azuTot - azuDisp);
        if (salTot > salDisp) printf("- Faltan %.1f g de sal\n", salTot - salDisp);
    }
}