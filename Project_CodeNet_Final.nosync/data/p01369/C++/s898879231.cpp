#include <bits/stdc++.h>
using namespace std;
int main(void){
    std::deque<char> left{'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
    string s;
    while (cin>>s) {
        if (s=="#") {
            break;
        } else {
            string flag="";
            int count=0;
            for (int i=0;i<s.size();i++) {
                if (i==0) {
                    if (find(left.begin(),left.end(),s.at(i))!=left.end()) {
                        flag="left";
                    } else {
                        flag="right";
                    }
                } else {
                    if ( flag=="left"&&find( left.begin(),left.end(),s.at(i) )==left.end() ) {
                        count++;
                        flag="right";
                    } else if ( flag=="right"&&find( left.begin(),left.end(),s.at(i) )!=left.end() ) {
                        count++;
                        flag="left";
                    }
                }
            }
            cout<<count<<endl;
        }
    }
}

