#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ca,cb;
    for(int i=0;i<3;i++){
        char ch = s[i];
        if(ch=='A'){
            ca++;
        }
    }
    if(ca>0&&ca<=2){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
	return 0;
}
