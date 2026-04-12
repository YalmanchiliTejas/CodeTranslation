#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int numn , numk;
    string str;
    cin >> numn >> str >> numk;
    string s = str.substr(numk-1,1);
    string ans;
    for(int i = 0; i< numn; i++){
        if(str.substr(i,1)!=s){
            ans += "*";
        }else{
            ans += str.substr(i,1);
        }
    }

    cout << ans << endl;
    return 0;
}