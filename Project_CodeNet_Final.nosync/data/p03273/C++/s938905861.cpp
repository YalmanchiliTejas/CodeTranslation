#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    char arr[100][100];
    for(int i=0;i<n;i++)
      {
        for(int j =0;j<m;j++)
         cin >> arr[i][j];
      }
    int c[100] = {0};
    for(int i=0;i<n;i++)
    {
        bool bo = false;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == '#') bo =  true;
        }
        if(bo) c[i]++;
    }
    int b[100] = {0};
    for(int i=0;i<m;i++)
    {
        bool bo = false;
        for(int j=0;j<n;j++)
        {
            if(arr[j][i] == '#') bo =  true;
        }
        if(bo) b[i]++;
    }
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<m; j++)
         {
            if(c[i]&&b[j])
            cout << arr[i][j];
        }
        if(c[i])
        cout << endl;
    }
}
