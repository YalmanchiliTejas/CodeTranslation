#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
#define all(x) x.begin(),x.end()
#define l_b lower_bound
#define u_b upper_bound
#define pb push_back
#define MOD 1000000007
void fastio(void);

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;  cin>>t;
    if(t<30)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    return 0;
}

void fastio(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}