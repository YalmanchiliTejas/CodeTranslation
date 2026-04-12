#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<int> alp(30);
    for(int i=0;i<n;i++){
        cin >> s;
        vector<int> temp(30);
        for(int j=0;j<s.size();j++){
            temp[s[j]-'a']++;
        }
        for(int l=0;l<26;l++){
            if(i==0){
                alp[l]=temp[l];
            }
            else{
                alp[l]=min(alp[l],temp[l]);
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<alp[i];j++){
            printf("%c",'a'+i);
        }
    }
    cout << endl;
}
