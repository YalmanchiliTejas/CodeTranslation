#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const int MOD = 1000000007;

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> a(M);
    vector<int> b(M);
    map<int,vector<int>> path;
    REP(i,M){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        path[a[i]].push_back(b[i]);
        path[b[i]].push_back(a[i]);
    }
    vector<int> vertex;
    REP(i,N)vertex.push_back(i);//頂点番号の並び
    ll cnt = 0;

    do{
        //print(vertex);
        REP(i,N-1){
            if(find(path[vertex[i]].begin(),path[vertex[i]].end(),vertex[i+1]) == path[vertex[i]].end()){
                // not connected
                break;
            }
            if(i==N-2){
                cnt++;
            }
        }
    }while(next_permutation(vertex.begin()+1,vertex.end()));
    cout<<cnt<<endl;
}