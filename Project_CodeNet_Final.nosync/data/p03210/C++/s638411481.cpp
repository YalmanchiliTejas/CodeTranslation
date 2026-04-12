#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int x;
    cin >> x;
    string ans ="NO";
    if(x==7||x==5||x==3){
        ans = "YES";
    }
    cout << ans << endl;
}
