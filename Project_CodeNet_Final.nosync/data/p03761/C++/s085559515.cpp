#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    vector<int>alp2(26,1e9);
    for(int i=0; i<n; i++){
        vector<int>alp1(26,0);
        cin >> s;
        for(int i=0; i<s.size(); i++){
            alp1[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            alp2[i] = min(alp1[i],alp2[i]);
        }
    }
    for(int i=0; i<26; i++){
        if(alp2[i]==1e9) continue;
        else{
            for(int j=0; j<alp2[i]; j++)
            cout << (char)(i+'a');
        }
    }
    cout << endl;
    return 0;
}