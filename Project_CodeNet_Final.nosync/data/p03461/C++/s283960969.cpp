#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.in", "r", stdin);
    int A, B;
    scanf("%d %d", &A, &B);
    vector< vector<int> > constraints(A+1, vector<int>(B+1,-1));
    for(int i=1; i<=A; i++)
    {
        for(int j=1; j<=B; j++)
        {
            scanf("%d", &constraints[i][j]);
        }
    }
    int nb_nodes=202;
    vector< vector<int> > adjacency_matrix(nb_nodes, vector<int>(nb_nodes, -1));
    for(int i=1; i<=A; i++)
    {
        for(int j=1; j<=B; j++)
        {
            int use1=-1;
            int use2=-1;
            for(int k1=0; k1<=100 && use1==-1; k1++)
            {
                for(int k2=0; k2<=100 && i*k1+j*k2 <= constraints[i][j] && use1==-1; k2++)
                {
                    bool ok=true;
                    int t=constraints[i][j]-i*k1-j*k2;
                    for(int l=1; l<=A && ok; l++)
                    {
                        for(int m=1; m<=B && ok; m++)
                        {
                            if(!(k1*l+k2*m+t >= constraints[l][m])) ok=false;
                        }
                    }
                    if(!ok) continue;
                    use1=k1;
                    use2=k2;
                }
            }
            //cerr << use1 << " " << use2 << endl;
            if(use1==-1)
            {
                printf("Impossible\n");
                return 0;
            }
            int t=constraints[i][j]-i*use1-j*use2;
            adjacency_matrix[use1][201-use2]=t;
        }
    }
    int extra=0;
    for(int i=0; i<nb_nodes; i++)
    {
        for(int j=0; j<nb_nodes; j++)
        {
            if(adjacency_matrix[i][j] != -1) extra++;
        }
    }
    printf("Possible\n");
    printf("202 %d\n", 200+extra);
    for(int i=0; i<=99; i++)
    {
        printf("%d %d X\n", i+1, i+2);
    }
    for(int i=101; i<=200; i++)
    {
        printf("%d %d Y\n", i+1, i+2);
    }
    for(int i=0; i<nb_nodes; i++)
    {
        for(int j=0; j<nb_nodes; j++)
        {
            if(adjacency_matrix[i][j] != -1)
            {
                printf("%d %d %d\n", i+1, j+1, adjacency_matrix[i][j]);
            }
        }
    }
    printf("%d %d\n", 1, 202);
    return 0;
}
