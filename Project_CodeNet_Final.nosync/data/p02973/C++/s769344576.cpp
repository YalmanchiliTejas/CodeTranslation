#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const bool debug = false;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    vector<int> lst;
    lst.push_back(a.at(0));

    if(debug){    
        cout << "lst:";
        rep(j,lst.size()) cout << lst.at(j) << " ";
        cout << endl;
    }
    for(int i=1;i<n;i++) {
        int l = -1,r = lst.size();
        while(l+1<r){
            int x = (l+r)/2;
            if(lst.at(x) < a.at(i)) r = x;
            else l = x;
        }

        if(debug) cout << a.at(i) << " r:" << r << endl;

        if(r == lst.size()){
            lst.push_back(a.at(i));
        }else{
            lst.at(r) = a.at(i);
        }

        if(debug){
            cout << "lst:";
            rep(j,lst.size()) cout << lst.at(j) << " ";
            cout << endl;
        }
    }

    cout << lst.size() << endl;
    return 0;
}