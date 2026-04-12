#include <iostream>
#include <string>
using namespace std;

int main(){
string s;
bool f=0;
cin >> s;

//全ての要素が等しければ運航しない->No
for(int i=0; i<s.length(); i++){
    if(s[0]!=s[i]) f=1; //一致しない要素があるので運航あり 
}
if(f) cout <<"Yes" <<endl;
else cout <<"No" <<endl;

return 0;
}
