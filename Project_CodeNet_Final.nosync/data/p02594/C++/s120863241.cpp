#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define fi firstS
#define mp make_pair

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
}

int main(){
    setIO(); 
    int n;
    cin >> n;
    if(n >= 30){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;   
}
