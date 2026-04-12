#include <bits/stdc++.h>
using namespace std;
int main()
{
    string word;
    bool flag = false;
    cin>>word;
    for(int i=0;i<word.length()-1;i++){
        if((word[i]=='B'&&word[i+1]=='A')||(word[i]=='A'&&word[i+1]=='B')){
            flag = true;
        }
    }
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
