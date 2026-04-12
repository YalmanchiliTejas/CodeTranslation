#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    bool rev = false;
    list<int> a;
    for(int i=0;i<N;i++){
        int v;
        cin >> v;
        if(rev) a.push_front(v);
        else a.push_back(v);
        rev = !rev;
    }

    vector<int> b(a.begin(), a.end());
    if(rev){
        for(int i=N-1;i>0;i--){
            cout << b[i] << " ";
        }
        cout << b[0] << endl;
    }else{
        for(int i=0;i<N-1;i++){
            cout << b[i] << " ";
        }
        cout << b[N-1] << endl;
    }
    return 0;
}