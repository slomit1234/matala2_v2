#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

void InitializeMatrix(int adj[N][N])
{
	printf("Enter the Matrix values:\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
}
void IsRouteExist(int adj[N][N])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	int m = 0;
	char dump = 0;
	int tempadj[N][N];
	
	for (n=0; n<N; n++) //copy by value  the matrix
	{ 
		for (m=0; m<N; m++)
		{
			if(adj[n][m] != 0)
			{
				tempadj[n][m] =1;
			}
			else
			{
				tempadj[n][m] =0;
			}
		}
	}
	
	printf("Enter the i's element:\n");
	scanf("%d%c", &i,&dump);
	printf("Enter the j's element:\n");
	scanf("%d%c", &j,&dump); 
	
	if (adj[i][j] != 0)
	{
		printf("True");
	}
	else if(i == j)
	{
		printf("False");
	}
	else
	{
		for(k=0; k<N; k++)
		{
			for(n=0; n<N; n++)
				for(m=0; m<N; m++)
					if(tempadj[n][m] == 0)
					{
						if(tempadj[n][k] != 0 && tempadj[k][m]!=0)
							tempadj[n][m]=1;
					}
		}
		
		if(tempadj[i][j] != 0)
		{
			printf("True");
		}
		else
		{
			printf("False");
		}
	}
}
void ShortestRoute(int adj[N][N])
{
	
int src = 0;
int dst = 0;
int n = 0;
char dump = 0;
int res[N];
int arr[N];

printf("Enter the Source vertice:\n");
scanf("%d%c", &src, &dump);
printf("Enter the Destination vertice:\n");
scanf("%d%c", &dst, &dump);
   
    for (int i=0; i<N; i++)
	{
        res[i] = INT_MAX, arr[i] = 0;
	}
    res[src] = 0;

    for (int j=0; j<N-1; j++) 
	{
        n = min(res, arr);
		arr[n] = 1;
		for (int k=0; k<N; k++)
			if (!(arr[k]) && (adj[n][k]) && (res[n] != INT_MAX) && (res[n] + adj[n][k] < res[k]))
                res[k] = res[n] + adj[n][k];
    }
if(res[dst] == INT_MAX || res[dst] == 0)
{
	printf("-1");
}
else
	printf("%d",res[dst]);
}

int min(int res[], int arr[])
{
    // Initialize min value
    int m = INT_MAX, min;

    for (int i= 0; i<N; i++)
        if (arr[i] == 0 && res[i] <= m)
            m = res[i], min = i;

    return min;
}