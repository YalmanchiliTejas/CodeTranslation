#include <iostream>
using namespace std;

#define INF 114514810

int main(){
    int n;
    string s;
    int num[50][26];
    int total[26] = {0};
    for(int i=0; i<50; i++){
        for(int j=0; j<26; j++){
            num[i][j] = 0;
        }
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        for(auto c : s){
            num[i][c-'a']++;
        }
    }
    for(int i=0; i<26; i++){
        int num_min = INF;
        for(int j=0; j<n; j++){
            if(num[j][i] <= num_min){
                num_min = num[j][i];
            }
        }
        total[i] = num_min;
    }
    string ans = "";
    for(int i=0; i<26; i++){
        string str(total[i], 'a'+i);
        ans += str;
    }
    cout << ans;
    return EXIT_SUCCESS;
}