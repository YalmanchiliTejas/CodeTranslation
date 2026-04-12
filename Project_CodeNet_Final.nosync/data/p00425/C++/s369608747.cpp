#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<int, int>
#define p3i pair<pii, int>
#define pll pair<ll, ll>
#define p3l pair<pll, ll>
#define lseg L, (L+R)/2, N*2+1
#define rseg (L+R)/2+1, R, N*2+2
#define ub upper_bound
#define lb lower_bound
#define p_q priority_queue
#define MN 1000000009

int n, t;
string s;
int main(){
    while(cin >> n){
        int a[6]={1, 2, 3, 4, 5, 6}, c=1;
        if (n==0) return 0;
        for (int l=0; l<n; ++l){
        cin >> s;
        if (s=="North"){
            t=a[0];
            a[0]=a[1];
            a[1]=a[5];
            a[5]=a[4];
            a[4]=t;
        }
        if (s=="East"){
            t=a[0];
            a[0]=a[3];
            a[3]=a[5];
            a[5]=a[2];
            a[2]=t;
        }
        if (s=="West"){
            t=a[0];
            a[0]=a[2];
            a[2]=a[5];
            a[5]=a[3];
            a[3]=t;
        }
        if (s=="South"){
            t=a[0];
            a[0]=a[4];
            a[4]=a[5];
            a[5]=a[1];
            a[1]=t;
        }
        if (s=="Right"){
            t=a[1];
            a[1]=a[2];
            a[2]=a[4];
            a[4]=a[3];
            a[3]=t;
        }
        if (s=="Left"){
            t=a[1];
            a[1]=a[3];
            a[3]=a[4];
            a[4]=a[2];
            a[2]=t;
        }
        c+=a[0];
        //cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << ' ' << a[4] << ' ' << a[5] << endl;
        }
        cout << c << endl;
    }
    return 0;
}