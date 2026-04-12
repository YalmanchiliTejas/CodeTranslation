#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll a[1000000];
ll b[1000000];
int main(){
    cin >> n;
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) b[i]=0;

    ll cnt=0;
    b[0] = a[n-1];
    for(ll i=n-2; i>=0; i--){
        if( a[i] >= b[cnt]){
            cnt++;
            b[cnt] = a[i];
        }else{
            for( ll j=0; j<=cnt; j++){
                if( j==cnt) b[j] = a[i];
                if( b[j] > a[i]){
                    b[j] = a[i];
                    break;
                }
            }

        }
        /*
        cerr << i <<", " <<cnt << endl << "--";
        for( ll k=0; k<=cnt; k++){
            cerr << b[k] <<", ";
        }
        cerr << endl;
        */
        
    }

    cout << cnt +1 << endl;
    return 0;
}