#ifndef _MY_MAT_H
#define _MY_MAT_H

	#include <stdio.h>
	#include <limits.h>
	#define N 10

	void InitializeMatrix(int adj[N][N]);
	void IsRouteExist(int adj[N][N]);
	void ShortestRoute(int adj[N][N]);
	int min(int res[N], int arr[N]);
		
	#endif