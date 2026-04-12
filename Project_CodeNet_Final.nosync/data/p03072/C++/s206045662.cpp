#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
int f[50];
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
        cin >> f[i];
    int cnt=0;
    int minn=f[0];
    for(int i=0;i<n;i++){
        if(f[i]>=minn){
            cnt++;
            minn=f[i];
        }
    }
    cout << cnt <<endl;
    return 0;
}
