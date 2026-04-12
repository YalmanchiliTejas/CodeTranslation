#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reps(i,s,n) for(int (i)=(s);(i)<(n);(i)++)
#define repr(i,n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define all(v) (v).begin(),(v).end()
#define chmax(a, b) a = max((a),(b))
#define chmin(a, b) a = min((a),(b))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000
 
 
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
 
int main() {
    int n;
    cin>>n;
    vint a(n);
    vint check(n);
    rep(i,n)cin>>a[i];
    vint table;

    rep(i,n){
        if(table.size()>=1){
            if(a[i]<=*(table.begin())){
                table.insert(table.begin(),a[i]);
            }
            else{
                auto iter=lower_bound(all(table),a[i]);
                //cout<<iter-table.begin()<<endl;
                if(iter==table.end()){
                    *(table.end()-1)=a[i];
                }
                else{
                    *(iter-1)=a[i];
                }
                /* 
                int start=0;
                int end=table.size();
                while(true){
                    int middle=(start+end)/2;
                    if(table[middle]<a[i]){
                        start=middle;
                    }
                    else{
                        end=middle+1;
                    }
                    if(end-start<=1){
                        break;
                    }
                    //cout<<start<<" "<<end<<endl;
                }
                */
            }
        }
        else{
            table.insert(table.begin(),a[i]);
        }



    }
    //rep(i,table.size())cout<<table[i]<<endl;
    cout<<table.size()<<endl;
}