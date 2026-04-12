#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n){
        cin >> s.at(i);
    }

    if(n==1){
        sort(s.at(0).begin(), s.at(0).end());
        cout << s.at(0) << endl;
        return 0;
    }

    string v = "";
    for(int i=0; i<s.at(0).size(); i++){
        bool ok = false;
        for(int j=1; j<n; j++){
            bool notok = false;
            for(int k=0; k<s.at(j).size(); k++){
                if(s.at(0).at(i)==s.at(j).at(k)) {
                    s.at(j).at(k) = '!'; 
                    break;
                }

                if(k==s.at(j).size()-1){
                   notok = true; 
                }
            }
            if(notok) break;

            if(j==n-1){
                ok = true;
            }
        }
        if(ok){
            v.push_back(s.at(0).at(i));
        }
    }

    if(v.size()!=0) {
        sort(v.begin(), v.end());
        cout << v << endl;
    }
    else cout << endl;

    return 0;
}
