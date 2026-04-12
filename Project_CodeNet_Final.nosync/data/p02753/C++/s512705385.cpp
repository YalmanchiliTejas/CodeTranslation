#include<iostream>

using namespace std;

int main(){
    string a,ans;
    cin >> a;
    if(a == "AAA"||a == "BBB"){
        ans = "No";
    }else{
        ans = "Yes";
    }
    cout << ans << endl;
}