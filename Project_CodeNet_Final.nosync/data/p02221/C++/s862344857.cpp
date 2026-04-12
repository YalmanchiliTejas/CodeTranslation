#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ans[1<<20];
string s;
vector<int> simu(vector<int> &v){
    int i,n = v.size();
    vector<int> w;
    for(i=0;i<n;i+=2){
        int x = max(v[i] - v[i + 1],v[i + 1] - v[i]);
        if(s[x - 1]=='0') w.push_back(min(v[i],v[i + 1]));
        else w.push_back(max(v[i],v[i + 1]));
    }
    return w;
}

void solve(vector<int> v,int dig, int num){
    int i,n = v.size();
    if(n==1){
        ans[num] = v[0];
        //cout << v[0] << endl;
        return ;
    }
    vector<int> w;
    for(int i=1;i<n;i++){
        w.push_back(v[i]);
    }
    w.push_back(v[0]);
    solve(simu(v),dig + 1,num);
    solve(simu(w),dig + 1,num|(1<<dig));
}

vector<int> v;
int main(){
    int i,n;
    cin >> n >> s;
    for(i=0;i<(1<<n);i++){
        int x; cin >> x;
        v.push_back(x);
    }
    solve(v,0,0);
    for(i=0;i<(1<<n);i++){
        cout << ans[i] << endl;
    }
}
