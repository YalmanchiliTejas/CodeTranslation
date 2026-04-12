#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n,i,j;
    vector<int> alpha(26,0);
    cin >> n;
    string s;
    cin >> s;
    for(i = 0;i < s.size();++i){
        ++alpha.at((int)s.at(i)-97);
    }

    for(i = 1;i < n;++i){
        vector<int> temp_alpha(26,0);
        cin >> s;
        for(j = 0;j < s.size();++j){
            ++temp_alpha.at((int)s.at(j)-97);
        }
        for(j = 0;j < alpha.size();++j){
            alpha.at(j) = min(alpha.at(j), temp_alpha.at(j));
        }
    }

    string ans = "";

    for(i = 0;i < alpha.size();++i){
        for(j = 0;j < alpha.at(i);++j){
            ans += (char)(i+97);
        }
    }
    cout << ans << endl;
    return 0;
}