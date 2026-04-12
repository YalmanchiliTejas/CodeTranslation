#include<bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    std::map<char,int> map;
    std::string s;
    std::cin >> s;
    for(auto i : s)map[i]++;

    for(int i = 0 ; i < n -1 ; i++){
        std::string k;
        std::cin >> k;
        std::map<char,int> tmp;
        for(auto j : k)tmp[j]++;
        for(auto j : map){
            map[j.first] = std::min(tmp[j.first],map[j.first]);
        }
    }
    std::string ans;
    for(auto i : map){
        for(int j = 0; j < i.second; j++)ans.push_back(i.first);
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans << std::endl;
}