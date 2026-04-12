#include <bits/stdc++.h>
#define _Sync ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
#define _End return cout << '\n' , 0 ;
#define fo(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mod 1000000007
#define debug(x) cout <<#x << " = " << x << endl
#define PI 3.14159265
#define MAXN 100001

using namespace std;


int main ()
{
    _Sync
    //freopen("D:/input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> data(n);
    fo(i,0,n){
        cin>>data[i];
    }
    int ans =0;
    bool valido = false;
    fo(i,0,n){
        valido =true;
        fo(j,0,i){
            if(data[i]<data[j]){
               valido = false;
               break;
            }
        }
        if(valido)ans++;
    }
    cout<<ans<<endl;
}
