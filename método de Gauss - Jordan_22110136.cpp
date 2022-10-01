//Aranzazú Hannay Gomez Faustino 
//22110136  CETI COLOMOS

#include <stdio.h>
#include <stdlib.h>

void data(int *size, float mat1[][51]);
void data_scale(int size1, float mat2[][51]);
void solution(int Dim, float Sist[][51]);


int main(void)
{
	system("color 5F");
    int i,size;
    float mat[50][51];
    data(&size,mat);
    system("PAUSE()");
	system("CLS()");
    printf("\t\n    MATRIZ: \n\n");
    data_scale(size,mat);
    solution(size,mat);
    printf("\t\nSolucion:\n");
    for(i=1;i<=size;i++)
        printf("\n X%d=%f \n",i,mat[i][size+1]);
    
	scanf("");
    return(0);
}


void data(int *size,float mat1[][51])
{
    int H,A;
    printf("\t------------------------------------------------\n");
    printf("\n\t    SISTEMA DE ECUACIONES POR GAUS JORDAN\n");
    printf("\n\t-----------------------------------------------\n");
    printf("\n\n\n CONSTANTES: ");
    scanf("%d",&*size);
    printf("\n Variables de la matriz:\n\n");
    printf("\n\n\t-------------------------------------------------\n");
    printf("\n\t                 MATRIZ :\n");
    for(H=1;H<=*size;H++)
        for(A=1;A<=*size;A++)
        {
        printf("\n\tVALORES DE LA MATRIZ(%d,%d):",H,A);
    scanf("%f",&mat1[H][A]);
    }
    printf("\n\t-------------------------------------------------\n");
	printf("\n\n\n RESULTADO:\n");
    for(H=1;H<=*size;H++){
        printf("\n VECTOR(%d): ",H);
        scanf("%f",&mat1[H][*size+1]);
    }
    }

void data_scale(int escala, float mat2[][51])
{
    int x,y;
    for(x=1;x<=escala;x++)
        {
        for(y=1;y<=(escala+1);y++)
        {
            printf("%7.2f",mat2[x][y]);
            if(y==escala)
             printf("   |");
    }
		printf("\n");
    }
    }

void solution(int size, float mat[][51])
{
    int result,i,H,A,m;
    float pivote,x;

    for(i=1;i<=size;i++)
        {
        result=0;m=i;
        while(result==0)
        {
           if((mat[m][i]>0.0000001)||((mat[m][i]<-0.0000001)))
           {
                result=1;
    }
            else
                m++;
            }
        pivote=mat[m][i];
        for(H=1;H<=(size+1);H++)
            {
            x=mat[m][H];
            mat[m][H]=mat[i][H];
            mat[i][H]=x/pivote;
        }
        for(A=i+1;A<=size;A++)
            {
            x=mat[A][i];
            for(H=i;H<=(size+1);H++)
            {
                mat[A][H]=mat[A][H]-x*mat[i][H];
        }
    }
    }

    for(i=size;i>=1;i--)
        for(H=(i-1);H>=1;H--)
        {
        mat[H][size+1]=mat[H][size+1]-mat[H][i]*mat[i][size+1];
        mat[H][i]=0;
    }
}