#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int ab[26];
    int i;
    for(i = 0; i < 26; i++){
        ab[i] = 50;
    }
    
    string s;
    int j;
    for(i = 1; i <= n; i++){
        cin >> s;
        int cnt[26] = {0};
        for(j = 0; j < s.length(); j++){
            cnt[s[j] - 'a']++;
        }
        
        for(j = 0; j < 26; j++){
            if(cnt[j] < ab[j]){
                ab[j] = cnt[j];
            }
        }
    }
    
    for(i = 0; i < 26; i++){
        for(j = 1; j <= ab[i]; j++){
            cout << (char)(i + 'a');
        }
    }
    
    cout << endl;
    
    return 0;
}
