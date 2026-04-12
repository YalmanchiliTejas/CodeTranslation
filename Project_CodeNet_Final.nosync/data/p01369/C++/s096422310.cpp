#include <bits/stdc++.h>

using namespace std;


bool side(string& left, char key){
    for(int i = 0; i < left.size(); i++){
        if(left[i] == key)return true;
    }
    return false;
}

int main(){
    string str;
    string left = "qwertasdfgzxcvb";
    sort(left.begin(), left.end());
    while(cin >> str && str != "#"){
        bool isleft = side(left,str[0]);
        int ans = 0;
        for(int i = 1; i < str.size(); i++){
            if(isleft != side(left, str[i])){
                ans++;
                isleft = !isleft;
            }
        }
        cout << ans << endl;
    }

    return 0;
}


