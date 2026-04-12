#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;

int n, a[200005],b[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0;i <n; i ++){
        int tem = n-i-1;
        if(i%2==0){
            b[i/2] = a[tem];
        }
        else{
            b[n-(i+1)/2]= a[tem];
        }
    }
    for(int i = 0; i < n; i++)cout<<b[i]<<' ';

    return 0;
}
