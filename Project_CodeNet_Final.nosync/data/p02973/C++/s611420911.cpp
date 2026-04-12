#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0);
    for(int i=1;i<=N;i++) cin >> A[i];
    map<int,int> m;
    int ans = 0;
    for(int i=1;i<=N;i++){
        map<int,int>::iterator it = m.upper_bound(-A[i]);
        if(it==m.end()){
            m[-A[i]]++;
            ans++;
        }else{
            m[it->first]--;
            if(m[it->first]==0) m.erase(it);
            m[-A[i]]++;
        }
    }
    cout << ans << endl;
}