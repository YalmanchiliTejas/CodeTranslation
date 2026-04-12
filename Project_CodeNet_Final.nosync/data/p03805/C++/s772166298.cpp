#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;
#define ED return 0;
#define UP(a,b) ((a+(b-1))/b)
#define SORT(vec) sort(vec.begin(),vec.end());
#define DOUBLECHANGE(count) cout << setprecision(count);
#define REV(vec) reverse(vec.begin(),vec.end());
#define ipow(x) LL(pow(x))
#define EQUAL(vec1,vec2) equal((vec1).cbegin(), (vec1).cend(), (vec2).cbegin());
const int INF = 999999999;
const long long int mod = 1000000007;

int ans = 0;
void roop(int now,vector<vector<bool>> vec,vector<bool> leave,int N){
    bool end = true;
    for(int i = 0;i < N;i++){
        if(vec[now][i] && !leave[i]){
            leave[i] = true;
            roop(i,vec,leave,N);
            leave[i] = false;
        }
        if(!leave[i])end = false;
    }
    if(end){
        ans++;
    }
    return;
}

int main() {
   int N, M;
   cin >> N >> M;
   vector<vector<bool>> vec (N, vector<bool>(N,false));
   vector<bool> leave (N,false);
//   cout << "N = " << N << ",M = " << M << endl;
   for(int i = 0;i < M;i++){
//       cout << "I = " << i << endl;
       int a, b;
       cin >> a >> b;
       vec[a-1][b-1] = true;
       vec[b-1][a-1] = true;
   }
//   cout << "CIN END" << endl << "------------------------------------" << endl;
   leave[0] = true;
   roop(0,vec,leave,N);
   cout << ans << endl;
}
