#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;
 
int N;
 
vector<vector<int> > square1001Div2;
 
int main()
{
    while(true)
    {
        cin >> N;
         
        if(N == 0) { break; }
     
        square1001Div2 = vector<vector<int> >(N, vector<int>(N, 0));
         
        int ptrx = N / 2, ptry = N / 2 + 1;
         
        for(int rep = 1; rep <= N * N; rep++)
        {
            square1001Div2[ptry][ptrx] = rep;
             
            ptrx = (ptrx + 1) % N;
            ptry = (ptry + 1) % N;
             
            while(square1001Div2[ptry][ptrx] != 0 && rep != N * N)
            {
                ptrx = (ptrx + N - 1) % N;
                ptry = (ptry + 1) % N;
            }
        }
         
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << setw(4) << square1001Div2[i][j];
            }
             
            cout << endl;
        }
    }
     
    return 0;
}