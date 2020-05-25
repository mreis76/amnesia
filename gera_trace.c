#include <stdio.h>
#include <stdlib.h>

void selection_sort(int num[], int tam) { 
    int i, j, min, aux;
	// $a0 = num
	// $a1 = tam
	// $s0 = i
	// $s1 = j
	// $s2 = min
	// $t1 = tam - 1
	// $t2 = num[j] ou num[i]
	// $t3 = num[min]
	// $t4 = &num[j] ou &num[i]
	// $t5 = &num[min]
	
    printf("2 0"); 										// 				addi $t1, $a1, -1
	// mostra a matriz inicial
    printf(" num={ ");
	for (int i = 0; i < tam; i ++)
        printf("%d ", num[i]);
    printf("}\n");

    printf("2 1\n"); 									// 				move $s0, $zero
    i = 0;
    for (;;)
    {
														// :fori
        printf("2 2\n"); 								// 				bge $s0, $t1, endfori
        if (i >= (tam-1)) break;
        
        printf("2 3\n"); 								// 				move $s2, $s0
        min = i;

        printf("2 4\n"); 								// 				addi $s1, $s0, 1
        j = (i+1);
        for (;;)
        {
														// :forj
            printf("2 5\n"); 							// 				bge $s1, $a1, endforj
            if (j >= tam) break;

            printf("2 6\n"); 							// 				addi $t4, $a0, $s1
            printf("2 7\n"); printf("1 %x\n", j+24);	// 				lw $t2, ($t4)
            printf("2 8\n"); 							// 				addi $t5, $a0, $s2
            printf("2 9\n"); printf("1 %x\n", min+24);	// 				lw $t3, ($t5)
            
            printf("2 a\n"); 							//				blt $t2, $t3, fimifj
            if(num[j] < num[min]) 
            {
                printf("2 b\n"); 						// 				move $s2, $s1
                min = j;
            }
														// :fimifj
            printf("2 c\n"); 							// 				addi $s1, $s1, 1
            j++;
            
            printf("2 d\n"); 							// 				j forj
        }
														// :endforj
        printf("2 e\n"); 								// 				addi $t4, $a0, $s0
        printf("2 f\n"); printf("1 %x\n", i+24); 		// 				lw $t2, ($t4)
        printf("2 10\n"); 								// 				addi $t5, $a0, $s2
        printf("2 11\n"); printf("1 %x\n", min+24); 	// 				lw $t3, ($t5)
        printf("2 12\n"); 								// 				bne $t2, $t3, fimifi
        
        if (num[i] != num[min]) {
            printf("2 13\n"); printf("0 %x\n", i+24); 	// 			sw $t3, ($t4)
            printf("2 14\n"); printf("0 %x\n", min+24); // 			sw $t2, ($t5)
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }

														// :fimifi
        printf("2 15\n"); 								// 				addi $s0, $s0, 1
        i++;
        
        printf("2 16\n"); 								// 				j fori
    }
														// :endfori
    printf("2 17"); 									//
	// mostra a matriz ordenada
    printf(" num={ ");
	for (int i = 0; i < tam; i ++)
        printf("%d ", num[i]);
    printf("}\n");
}

int main() {
    int matriz[100];
    int tam = 100;
    
    for (int i = 0; i < tam; i ++) {
        matriz[i] = rand() % 10000;
    }
    
    selection_sort(matriz, tam);
    
    return 0;
}

