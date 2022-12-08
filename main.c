#include <stdio.h>
#include "my_mat.h"

int main()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	char choise = 0;
	char dump = 0;
	int AdjacencyMatrix[N][N];

	for (i=0; i<N; i++) //Initialize in 0's 
	{ 
		for (j=0; j<N; j++)
		{
			AdjacencyMatrix[i][j] = 0;
		}
	}

	do
	{
		//display manu to the user & get an input
		printf("\nplease choose a function\n A- insert Adjacency Matrix.\n B- Find if Route Exists.\n C- Present The Shortest Route\n D- Exit\n");
		scanf("%c%c",&choise,&dump); //dump is for the tab char
		//scanf("%c",&dump);
		//printf("\n$$%c$%c$\n",choise,dump);
		switch (choise) //char is represnted in ascii A=65 B=66 C=67 D=68
		{
			case 65:
			{
				InitializeMatrix(AdjacencyMatrix); // call first func
				scanf("%c",&dump); // last tab char
				break;
			}
			case 'B':
			{
				IsRouteExist(AdjacencyMatrix); // call second func
				scanf("%c",&dump); // last tab char
				break;
			}
			case 67:
			{
				ShortestRoute(AdjacencyMatrix);
				scanf("%c",&dump); // last tab char
				break;
			}
			case 68:
			{
				flag = 1;
				break;
			}
			default:
				flag = 1;
				break;
		}
	} while (flag == 0);

	return 0;
}