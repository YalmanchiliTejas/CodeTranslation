//omajinai
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//omajinai

int main(){

    // omajinai
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // omajinai

    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0;i < n;i ++){
        cin >> s.at(i);
    }

    sort(s.begin(),s.end());

    string ans1 = "",ans2 = "";

    ans1 = s.at(0);

    for(int i = 1;i < n;i ++){
        for(int j = ans1.size()-1;j >= 0;j --){
            for(int k = 0;k < s.at(i).size();k ++){
                if(ans1.at(j) == s.at(i).at(k)){
                    ans2 += ans1.at(j);
                    s.at(i).at(k) = '1';
                    break;
                }
            }
            ans1.pop_back();
            if(ans1.size() == 0){
                break;
            }
        }
        ans1 = ans2;
        ans2 = "";
        if(ans1.size() == 0){
            break;
        }
    }

    sort(ans1.begin(),ans1.end());
    cout << ans1 << endl;

}