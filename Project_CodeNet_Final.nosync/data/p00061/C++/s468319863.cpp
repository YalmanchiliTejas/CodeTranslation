#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    vector<int> s(101, -1);
    while(1){
        int a,b;
        scanf("%d,%d", &a,&b);
        if(a==0 && b==0) break;
        s[a] = b;
    }
    int n = s.size();
    vector<int> ord(n);
    for(int i=0; i<101; i++){
        if(s[i]==-1) continue;
        ord[i] = s[i];
    }
    sort(ord.begin(), ord.end(), greater<int>());
    ord.erase(unique(ord.begin(), ord.end()), ord.end());

    map<int, int> res;
    for(int i=0; i<(int)ord.size(); i++){
        res[ord[i]] = i+1;
    }

    int q;
    while(cin >> q){
        cout << res[s[q]] << endl;
    }
    
    return 0;
}

