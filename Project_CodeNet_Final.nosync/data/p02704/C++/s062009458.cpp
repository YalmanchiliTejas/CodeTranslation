#include <bits/stdc++.h>
using namespace std;

bool S[505], T[505];
unsigned long long U[505], V[505];

bool grid[505][505];
bool confirm[505][505];
short counterRow[505], counterCol[505];
unsigned long long ans[505][505];

bool checkNthBit(unsigned long long int num, int layer)
{
	return (num & (1llu << layer)) > 0;
}

void setConfirm(int layer, int N)
{
	
	//rows
	for(int i = 1; i <= N; i++)
	{
		if(S[i] == 0 && checkNthBit(U[i], layer))
		{
			for(int j = 1; j <= N; j++)
			{
				grid[i][j] = true;
				confirm[i][j] = true;
			}
		}
		
		else if(S[i] == 1 && ( !(checkNthBit(U[i], layer)) ) )
		{
			for(int j = 1; j <= N; j++)
			{
				grid[i][j] = false;
				confirm[i][j] = true;
			}
		}
	}
	
	//columns
	for(int j = 1; j <= N; j++)
	{
		if(T[j] == 0 && checkNthBit(V[j], layer))
		{
			for(int i = 1; i <= N; i++)
			{
				if(confirm[i][j] && grid[i][j] == false)
				{
					printf("-1\n");
					//printf("layer = %d, i = %d, j = %d, setConfirm\n", layer, i, j);
					
					exit(0);
				}
				
				grid[i][j] = true;
				confirm[i][j] = true;
			}
		}
		
		else if(T[j] == 1 && ( !(checkNthBit(V[j], layer)) ) )
		{
			for(int i = 1; i <= N; i++)
			{
				if(confirm[i][j] && grid[i][j])
				{
					printf("-1\n");
					//printf("layer = %d, j = %d, i = %d, setConfirm\n", layer, j, i);
					
					exit(0);
				}
				
				grid[i][j] = false;
				confirm[i][j] = true;
			}
		} 
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			counterRow[i] += grid[i][j];
			counterCol[j] += grid[i][j];
		}
	}
}

void setRest(int layer, int N)
{
	//row
	for(int i = 1; i <= N; i++)
	{
		//at least 1 zero.
		if(S[i] == 0 && checkNthBit(U[i], layer) == false)
		{
			if(counterRow[i] == N)
			{
				printf("-1\n");
				//printf("layer = %d, i = %d, setRest\n", layer, i);
				exit(0);
			}
		}
		
		//at least 1 one.
		else if(S[i] == 1 && checkNthBit(U[i], layer))
		{
			if(counterRow[i] == 0)
			{
				for(int j = 1; j <= N; j++)
				{
					if(confirm[i][j])
						continue;
					
					
					//column needs to have at least 1 zero.
					else if(T[j] == 0 && checkNthBit(V[j], layer) == false)
					{
						if(counterCol[j] + 1 == N)
							continue;
					}
					
					grid[i][j] = true;
					counterRow[i]++;
					counterCol[j]++;
					confirm[i][j] = true;
					break;
				}
				
				if(counterRow[i] == 0)
				{
					printf("-1\n");
					//printf("layer = %d, i = %d, setRest\n", layer, i);
					exit(0);
				}
			}
		}
	}
	
	//column
	for(int i = 1; i <= N; i++)
	{
		//at least 1 zero.
		if(T[i] == 0 && checkNthBit(V[i], layer) == false)
		{
			if(counterCol[i] == N)
			{
				printf("-1");
				printf("layer = %d, i = %d, setRest\n", layer, i);
				exit(0);
			}
		}
		
		//at least 1 one.
		else if(T[i] == 1 && checkNthBit(V[i], layer))
		{
			if(counterCol[i] == 0)
			{
				for(int j = 1; j <= N; j++)
				{
					if(confirm[j][i])
						continue;
					
					
					//column needs to have at least 1 zero.
					else if(S[j] == 0 && checkNthBit(U[j], layer) == false)
					{
						if(counterRow[j] + 1 == N)
							continue;
					}
					
					grid[j][i] = true;
					counterRow[j]++;
					counterCol[i]++;
					confirm[j][i] = true;
					break;
				}
				
				if(counterCol[i] == 0)
				{
					printf("-1\n");
					printf("layer = %d, i = %d, setRest\n", layer, i);
					exit(0);
				}
			}
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	for(int i = 1; i <= N; i++)
	{
		short Si;
		scanf("%hd", &Si);
		
		S[i] = Si;
	}
	
	for(int i = 1; i <= N; i++)
	{
		short Ti;
		scanf("%hd", &Ti);
		
		T[i] = Ti;
	}
	
	for(int i = 1; i <= N; i++)
	{
		scanf("%llu", &U[i]);
	}
	
	for(int i = 1; i <= N; i++)
		scanf("%llu", &V[i]);
		
	for(int i = 0; i < 64; i++)
	{
		memset(grid, 0, sizeof(grid));
		memset(confirm, 0, sizeof(confirm));
		
		for(int j = 1; j <= N; j++)
		{
			counterRow[j] = 0;
			counterCol[j] = 0;
		}
		
		setConfirm(i, N);
		setRest(i, N);
		
		for(int j = 1; j <= N; j++)
		{
			for(int k = 1; k <= N; k++)
			{
				ans[j][k] += (1llu << i) * grid[j][k];
			}
		}
	}
	
			
	for(int j = 1; j <= N; j++)
	{
		for(int k = 1; k <= N; k++)
			printf("%llu ", ans[j][k]);
				
		printf("\n");
	}
}
