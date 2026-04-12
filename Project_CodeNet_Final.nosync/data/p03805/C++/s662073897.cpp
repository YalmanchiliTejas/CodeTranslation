#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;




int main(void)
{
    /*
    ABC 054 C
    https://atcoder.jp/contests/abc054/tasks/abc054_c
    */
    int N_vertices, N_edges;
    cin >> N_vertices>> N_edges;

    vector< vector<int> > Graph(N_vertices, vector<int>(N_vertices, 0) );
    vector<int> permutation(N_vertices);
    for(int i=0; i<N_vertices; i++)
    {
        permutation[i] = i;
    }

    int i, j;
    for(int k=0; k<N_edges; k++)
    {
        cin >> i >> j;
        Graph[i-1][j-1] = 1;
        Graph[j-1][i-1]=1;
    }


    int comb = 0;
    bool flag = true;
    int pos, next;
    do
    {
        flag = true;
        pos = 0;
        for(int i=0; i<N_vertices-1; i++)
        {
            next = permutation[i+1];
            if(Graph[pos][next]==0)
            {
                flag=false;
                break;
            }
            pos = next;
        }
        if(flag) comb++;
    }while( next_permutation( permutation.begin()+1, permutation.end() ) );

    cout << comb << endl;



    return 0;
}
