#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    int A_cnt=0;
    cin>>s;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='A'){
            A_cnt++;
        }
    }
    if(A_cnt == 0 || A_cnt == 3) {
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}