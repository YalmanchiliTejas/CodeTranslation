#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool Check(vector<int> vec,int c){
    
    for(int i=0;i<vec.size();i++){if(vec[i] == c) return false;}
    return true;
}
int main(){
    
    int N,M,a,b,ans=0; cin >> N >> M;
    vector<vector<int>> data(N+1);
    vector<int> one_case;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        if(Check(data.at(a),b)) data.at(a).push_back(b);
        if(Check(data.at(b),a)) data.at(b).push_back(a);
    }
    for (int i=1;i<=N;i++) { one_case.emplace_back(i); }
    
    do {
        for(int i=0;i<N-1;i++){
            if(one_case[0] != 1)break;
            
            if(Check(data.at(one_case[i]),one_case[i+1]) == true) break;
            
            if(i == N-2) ans++;
        }
    } while (next_permutation(one_case.begin(), one_case.end()));
    
    cout << ans << endl;
}