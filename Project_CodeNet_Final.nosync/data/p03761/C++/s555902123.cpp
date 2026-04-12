#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<map<char,int> > mapVec;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        map<char, int> char_map;
        for(int i=0;i<26;i++){
            char_map['a'+i] = 0;
        }
        for(int j=0;j<str.length();j++){
            char_map[str[j]] = char_map[str[j]]+1;
        }
        mapVec.push_back(char_map);
    }

    for(int i=1;i<mapVec.size();i++){
        for(auto itr=mapVec[i].begin();itr!=mapVec[i].end();itr++){
            mapVec[0][itr->first]=min(itr->second,mapVec[0][itr->first]);
        }
    }

    for(auto itr=mapVec[0].begin();itr!=mapVec[0].end();itr++){
        for(int i=0;i<itr->second;i++){
            cout << itr->first;
        }
    }

    cout << "" << endl;
    return 0;
}
