#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,w,l,d,flag=0;
    string s;
    while (cin>>n) {
        if (n==0) {
            break;
        } else {
            if (flag!=0) {
                cout<<endl;
            }
            std::multimap<int,string,greater<int>> map;
            int score=0;
            for (int i=0;i<n;i++) {
                cin>>s>>w>>l>>d;
                score=w*3+d;
                map.insert(make_pair(score,s));
            }
            for (auto const& entry: map) {
                cout<<entry.second<<","<<entry.first<<endl;
            }
            flag=1;
        }
    }
    
}

