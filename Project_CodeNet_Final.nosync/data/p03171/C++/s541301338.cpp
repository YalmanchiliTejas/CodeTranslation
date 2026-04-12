#include <iostream>

using namespace std;
#define N 3030
int i,l,n;
long long v[N],a[N][N][2],x,y,z,t;
int main()
{
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    for (i = 0; i < n; ++i)
        a[i][i][n & 1] = v[i];
    for (l = 1; l < n; ++l){
        for (i = 0; i + l < n; ++i){
            if ((n - l) & 1){
                x = v[i] + a[i + 1][i + l][1];
                y = a[i + 1][i + l][0];
                z = v[i + l] + a[i][i + l - 1][1];
                t = a[i][i + l - 1][0];
                if (x > z){
                    a[i][i + l][0] = y;
                    a[i][i + l][1] = x;
                }
                else{
                    a[i][i + l][0] = t;
                    a[i][i + l][1] = z;
                }
            }
            else{
                x = v[i] + a[i + 1][i + l][0];
                y = a[i + 1][i + l][1];
                z = v[i + l] + a[i][i + l - 1][0];
                t = a[i][i + l - 1][1];
                if (x > z){
                    a[i][i + l][1] = y;
                    a[i][i + l][0] = x;
                }
                else{
                    a[i][i + l][1] = t;
                    a[i][i + l][0] = z;
                }
            }
        }
    }
    cout << a[0][n - 1][1] - a[0][n - 1][0];
    return 0;
}
