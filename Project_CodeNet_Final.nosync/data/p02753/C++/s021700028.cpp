///Astalavista Code........~CodeSlayer007
#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <iterator>
typedef  long long int ll;
typedef  long double ld;
#define PT(x) cout << (#x) << " is " << (x) << endl;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
#define SPD_emergency ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1000000007;
#define int long long
void PV( vi v) { for(ll i=0 ; i<v.size() ; i++) cout<< v[i] << " "; cout<< endl;}
void PA( int v[] , int n ){ for(ll i=0 ; i<n ; i++)cout<< v[i] << " " ; cout<< endl;}

signed  main(){
     SPD_emergency
   //ll t; cin>> t; while(t--)
    {
        string s;
        cin>>s;
        if(s[0]==s[1] && s[1]==s[2])cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
