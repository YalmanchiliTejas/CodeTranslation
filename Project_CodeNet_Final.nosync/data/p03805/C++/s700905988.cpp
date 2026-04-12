#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define print(s) cout << s << endl; return 0;
#define printFix(n,i) cout << fixed << setprecision(i) << n << endl; return 0;
#define yes cout << "Yes" << endl; return 0;
#define no cout << "No" << endl; return 0;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,n) for (int i = 1; i < (n)+1; ++i)
#define bitrep(i,n) for (int i = 0; i < (1<<(n));i++)
#define isOne(bit,i) (bit & (1 << i))
using ll = long long;
using pii = pair<int, int>;
using si = set<int>;

const ll modseed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getValues(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
int N,M,cnt;

int main(){
  cin >> N >> M;
  vector<set<int>> lines(N+1);
  for(int i=1;i<M+1;i++){
    int a,b;
    cin >>a >> b;
    if(!lines.at(a).count(b)){
      lines.at(a).insert(b);  
    }
    if(!lines.at(b).count(a)){
      lines.at(b).insert(a);
    }
  }

  vector<int> cases(N);
  rep(i,N){
    cases.at(i) = i+1;
  }
  do{
    if(cases.at(0)!=1){
      continue;
    }
    int ok=0;
    for(int i=0;i<N-1;i++){
        if(lines.at(cases.at(i)).count(cases.at(i+1))){
          ok++;
        }else{
          break;
        }
    }
    if(ok==N-1){
      cnt++;
    }
  }while(next_permutation(cases.begin(),cases.end()));
  printl(cnt);
}
