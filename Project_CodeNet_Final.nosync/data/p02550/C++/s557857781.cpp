#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,m,n) for(ll i=(m);i<(n);i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back





int main(){


    ll n,x,m;
    cin>>n>>x>>m;

    vector<ll> data;
    data.pb(x);

    set<ll> check;
    check.insert(x);

    while (check.find((data.at(int(data.size())-1)*data.at(int(data.size())-1))%m)==check.end()){
        ll tmp=(data.at(int(data.size())-1)*data.at(int(data.size())-1))%m;
        data.pb(tmp);
        check.insert(tmp);
    }


    ll secondnumber=(data.at(int(data.size())-1)*data.at(int(data.size())-1))%m;

    ll length=int(data.size());


    ll firstappear;

    for (int i=0;i<length;i++){
        if (data.at(i)==secondnumber){
            firstappear=i+1;
        }
    }

    ll answer=0;
  


    if (n<=length){
        rep(i,n){
            answer+=data.at(i);
        }
    }
  
  

    else {
        ll kaisu=(n-firstappear+1)/(length-firstappear+1);
        ll amari=(n-firstappear+1)%(length-firstappear+1);

        for (int i=0;i<=firstappear-2;i++){
            answer+=data.at(i);
        }

        ll tmp=0;
        for (int i=firstappear-1;i<=length-1;i++){
            tmp+=data.at(i);
        }
        answer+=tmp*kaisu;

        for (int i=firstappear-1;i<=firstappear+amari-2;i++){
            answer+=data.at(i);
        }



    }


  
  
  
  


    cout<<answer<<endl;














}