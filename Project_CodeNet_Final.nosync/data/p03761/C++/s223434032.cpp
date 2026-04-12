#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[26] = {};
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int a[26] = {};
        for(auto c: s){
            a[c-'a']++;
        }
        if(i!=0){
            for(int i=0; i<26; i++){
                v[i] = min(v[i], a[i]);
            }
        }else{
            for(int i=0; i<26; i++){
                v[i] = a[i];
            }
        }
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<v[i]; j++){
            cout << char('a' + i);
        }
    }
    return 0;
}
