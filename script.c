#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int nr, i, j, c, k, minterm, m, e=0, MintermCounter=0, t, minterm1, e1=0, MintermCounter1=0;

    // Mintermat nga 1 ne 15
    int Minterms[16][4]= {
            {0, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0},
            {0, 0, 1, 1},
            {0, 1, 0, 0},
            {0, 1, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 1},
            {1, 0, 1, 0},
            {1, 0, 1, 1},
            {1, 1, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 1, 0},
            {1, 1, 1, 1},
    };


    printf("Sa minterma doni te futni? ");
    scanf("%d", &nr);
    // Minterma[indeksi][0, 1, 2, 3]
    int Minterma[nr][4];


    int MintermList[nr];
    printf("------------- \n");
    for(i=0; i<nr; i++){
        printf("Mintermi %d: ", i);
        scanf("%d", &MintermList[i]);
    }
    printf("------------- \n");


    for(i=0; i<nr; i++){
        for(j=0;j<4;j++){
            Minterma[i][j] = Minterms[MintermList[i]][j];
        }
    }

    for(i=0;i<nr;i++){
        printf("m%d: ", i);
        for(j=0; j<4; j++){
            printf("%d ", Minterma[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");


    int MintermTabele[nr][nr];
    int Mintermat[nr][2];

    // i eshte per rreshtin
    // k eshte per te kaluar neper rreshta
    // j eshte per te kontrolluar vlerat e rreshtit

    for(i=0; i<nr; i++){
		printf("\n-------------------- \n");
//		printf("Kemi rreshtin %d.\n", i);
        for(k=i+1; k<nr; k++){
//			printf("-------------------- \n");
//			printf("E krahasojme me rreshtin %d.\n", k);
            c=0;
            minterm = 0;
            for (j=0; j<4; j++){
                if(c>1){
                    break;
                }
                if(Minterma[i][j] == Minterma[k][j]){
//					printf("%d %d \n", Minterma[i][j], Minterma[k][j]);
                } else{
                    c++;
                    minterm = j;
//					printf("%d %d <<-- \n", Minterma[i][j], Minterma[k][j]);
                }
            }
            // Nese ndryshon vetem 1 bit krijo nje vektor te ri me
            if(c==1){
//				printf("Ndryshon vetem 1 bit, biti %d! Merret!\n", minterm+1);
                // Krijon nje tabele te re dhe i jep indeksin e tabelave
                Mintermat[e][0] = i;
                Mintermat[e][1] = k;

                // i jep vlerat Tabeles se re dhe aty ku ndryshon bit i jep vleren 2.
                for(m=0; m<4; m++){
                    if(m == minterm){
                        MintermTabele[e][m] = 2;
                    } else{
                        MintermTabele[e][m] = Minterma[i][m];
                    }
                }
//				printf("Mintermi: ");
				for(t=0; t<4; t++){
//					printf("%d ", MintermTabele[e][t]);
				}
                // rrit e qe sherben per te ruajtur tabelen, sepse nuk e kemi futur ne cikel, por e rritim manualisht
                // dhe MintermCounter qe sherben si counter mintermash
                e++;
                MintermCounter++;

//				printf("\n");
            } else{
//				printf("Ndryshon %d bit! Nuk merret!\n", c);
            }
        }

    }

    // Bejme te njejten gje sic beme me tabelen me siper

    int Mintermat1[nr][2];
    int MintermTabele1[nr][4];
    // i eshte per rreshtin
    // k eshte per te kaluar neper rreshta
    // j eshte per te kontrolluar vlerat e rreshtit

    for(i=0; i<nr; i++){
//		printf("\n-------------------- \n");
//		printf("Kemi rreshtin %d.\n", i);
        for(k=i+1; k<nr-1; k++){
//			printf("-------------------- \n");
//			printf("E krahasojme me rreshtin %d.\n", k);
            c=0;
            minterm1 = 0;
            for (j=0; j<4; j++){
                if(c>1){
                    break;
                }
                if(MintermTabele[i][j] == MintermTabele[k][j]){
//					printf("%d %d \n", MintermTabele[i][j], MintermTabele[k][j]);
                } else{
                    c++;
                    minterm1 = j;
//					printf("%d %d <<-- \n", MintermTabele[i][j], MintermTabele[k][j]);
                }
            }
            // Nese ndryshon vetem 1 bit krijo nje vektor te ri me
            if(c==1){
//				printf("Ndryshon vetem 1 bit, biti %d! Merret!\n", minterm+1);
                // Krijon nje tabele te re dhe i jep indeksin e tabelave
                Mintermat1[e1][0] = i;
                Mintermat1[e1][1] = k;

                // i jep vlerat Tabeles se re dhe aty ku ndryshon bit i jep vleren 2.
                for(m=0; m<4; m++){
                    if(m == minterm1){
                        MintermTabele1[e1][m] = 2;
                    } else{
                        MintermTabele1[e1][m] = MintermTabele[i][m];
                    }
                }
//				printf("Mintermi: ");
				for(t=0; t<4; t++){
//					printf("%d ", MintermTabele[e][t]);
				}
                // rrit e qe sherben per te ruajtur tabelen, sepse nuk e kemi futur ne cikel, por e rritim manualisht
                // dhe MintermCounter qe sherben si counter mintermash
                e1++;
                MintermCounter1++;

//				printf("\n");
            } else{
//				printf("Ndryshon %d bit! Nuk merret!\n", c);
            }
        }

    }

    printf("-------------------- \n");
    printf("-------------------- \n");
    printf("Mintermat 1\n");

    for(i=0; i<MintermCounter; i++){

        printf("%d %d :   ", Mintermat[i][0], Mintermat[i][1]);

        for(t=0; t<4; t++){
            printf("%d ", MintermTabele[i][t]);
        }
        printf("\n");
    }

    
    printf("-------------------- \n");
    printf("Mintermat 2\n");
    printf("-------------------- \n");

    for(i=0; i<MintermCounter1; i++){
        printf("%d %d %d %d :   ", Mintermat[Mintermat1[i][0]][0], Mintermat[Mintermat1[i][0]][1], Mintermat[Mintermat1[i][1]][0], Mintermat[Mintermat1[i][1]][1]);
        for(t=0; t<4; t++){
            printf("%d ", MintermTabele1[i][t]);
        }
        printf("\n");
    }
    printf("-------------------- \n");

//    printf("Implikantet 2\n");
//
//    printf("-------------------- \n");

    // krijojme nje vektor te ri ku futim te gjithe mintermat qe jane optimizuar akoma me shume
    // dhe me pas e krahasojme me te gjithe mintermat, mintermat qe nuk ndodhen ne vektor do jene implikante te pare
    // mintermat qe jane optimizuar akoma me shume i kontrollojme ne tabelen e dyte dhe i bejme ato implikante te pare..

    int MintermO[nr][2];
    int MintermOCounter = 0;
	int MintermI[nr][2];
    int MintermICounter = 0;

    for(i=0; i<MintermCounter; i++){
        for(j=0; j<e1; j++){
            if(Mintermat[i][0] == Mintermat[Mintermat1[j][0]][0] && Mintermat[i][1] == Mintermat[Mintermat1[j][0]][1]){
                MintermO[i][0] = Mintermat[i][0];
                MintermO[i][1] = Mintermat[i][1];
//                printf("Minterma %d dhe %d jane optimizuar\n", MintermO[i][0], MintermO[i][1]);
                MintermOCounter++;
                break;
            }
            
//            if(Mintermat[i][0] != Mintermat[Mintermat1[j][0]][0] && Mintermat[i][1] != Mintermat[Mintermat1[j][0]][1]){
//                MintermI[i][0] = Mintermat[i][0];
//                MintermI[i][1] = Mintermat[i][1];
//                printf("Minterma %d dhe %d jane implikante te pare\n", MintermI[i][0], MintermI[i][1]);
//                MintermICounter++;
//       //         break;
//            }
            
            if(Mintermat[i][0] == Mintermat[Mintermat1[j][1]][0] && Mintermat[i][1] == Mintermat[Mintermat1[j][1]][1]){
                MintermO[i][0] = Mintermat[i][0];
                MintermO[i][1] = Mintermat[i][1];
                printf("Minterma %d dhe %d jane optimizuar\n", MintermO[i][0], MintermO[i][1]);
                MintermOCounter++;
                break;
            }

//            if(Mintermat[i][0] != Mintermat[Mintermat1[j][1]][0] && Mintermat[i][1] != Mintermat[Mintermat1[j][1]][1]){
//                MintermI[i][0] = Mintermat[i][0];
//                MintermI[i][1] = Mintermat[i][1];
//                printf("Minterma %d dhe %d jane implikante te pare\n", MintermI[i][0], MintermI[i][1]);
//
//                MintermICounter++;
//       //         break;
 //           }
        }
    }
    printf("-------------------- \n");


	for(i=0; i<MintermOCounter; i++){
		printf("%d %d \n", MintermO[i][0], MintermO[i][1]);
	}
	
    printf("-------------------- \n");


	for(i=0; i<MintermICounter; i++){
		printf("%d %d\n", MintermI[i][0], MintermI[i][1]);
	}
		
    return 0;
}
