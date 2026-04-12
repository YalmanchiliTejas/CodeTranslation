#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x;
    scanf("%d",&x);
    vector<int> vec = {3,5,7};
    string ans = "NO";
    for(int i=0;i<3;i++){
        if (x == vec.at(i)) ans = "YES";
    }
    cout << ans << endl;
}
