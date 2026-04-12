#include<bits/stdc++.h>
using namespace std;
typedef pair<int64_t ,int64_t> P;

int main(){
    int n;
    cin >> n;

    string s ,t;
    cin >> s;
    sort(s.begin() ,s.end());

    for(int i=1;i<n;i++){
        string tmp = s;
        s.erase(0);
        cin >> t;
        sort(t.begin() ,t.end());
        for(int j=0;j<tmp.size();j++){
            for(int k=0;k<t.size();k++){
                if(tmp[j] == t[k]){
                    s.push_back(tmp[j]);
                    tmp.erase(j ,1);j--;
                    t.erase(k ,1);k--;
                    //cout << tmp << " " << t << endl;
                }
            }
        }
       // cout << s << endl;
    }

    cout << s << endl;
}