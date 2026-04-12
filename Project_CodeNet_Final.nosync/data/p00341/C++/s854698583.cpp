/*
　　　　 ∧＿∧　にっぽんちゃちゃちゃ
　／＼（　・∀・）／ヽ
（ ●　と　　　つ　● ）　にっぽんちゃちゃちゃ
　＼/⊂、 ノ　　＼ノ
　　　　　し'
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define Rep(j,n) for(int j=0;j<(int)(n);++j)
#define Repo(j,o,n) for(int j=o;j<(int)(n);++j)
#define Repone(j,n) for(int j=1;j<(int)(n);++j)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int long long
#define MOD 1000000007
#define INF 9223372036854775807

signed main(){
int x=0,y=0,z=0,w=0;
std::vector<int> v(12);
rep(i,12)std::cin >> v[i];
sort(all(v));
rep(i,12){
if(v[i]!=v[i-i%4])x++;
}
if(x==0)std::cout << "yes" << '\n';
else std::cout << "no" << '\n';
}

