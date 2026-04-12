#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    int N;
    cin >> N;
    map<char, int> mp;
    map<char, int> pre_mp;
    for(int n=0; n<N; n++) {
        string str;
        cin >> str;

        if(n==0) {
            for(int i=0; i<str.size(); i++) {
                mp[str[i]]++;
            }
            
            continue;
        }
        
        pre_mp.clear();
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            pre_mp[i->first]=i->second;
        }
        
        mp.clear();
        for(int i=0; i<str.size(); i++) {
            if(pre_mp.count(str[i]) && pre_mp[str[i]]>mp[str[i]]) {
                mp[str[i]]++;
            }
        }
    }
    
    for(auto i=mp.begin(); i!=mp.end(); i++) {
        for(int j=0; j<i->second; j++) {
            cout << i->first;
        }
    }
    cout << endl;

    return 0;
    
}