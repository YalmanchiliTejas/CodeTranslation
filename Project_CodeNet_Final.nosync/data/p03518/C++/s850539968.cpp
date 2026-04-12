#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int N;
int p[200];

void swaps(int k){
    for(int i=k;i<N;i++) swap(p[i],p[i-k]);
}

bool check(){
    for(int i=1;i<N;i++) if(p[i]<p[i-1]) return false;
    return true;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> p[i];
    vector<int> ans;
    while(!check()){
        if(p[0]!=0 && p[N-1]!=0 && p[0]<p[N-1]){
            swaps(N-1);
            ans.push_back(N-1);
        }
        swaps(1);
        ans.push_back(1);
    }
/*    for(int i=0;i<N;i++) cerr << p[i] << " ";
    cerr << endl;
*/    assert((int)ans.size()<=100000);
    cout << ans.size() << endl;
    for(auto x:ans) cout << x << endl; 
}