#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s[n];
    int min_size = 50;
    int index;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    string ans = "";
    for(char i = 'a'; i <= 'z'; i++){

        int min_count_char = 50;
        for(int j = 0; j < n; j++){
            int count_char = 0;
            for(int k = 0; k < s[j].size(); k++){
                if(s[j][k] == i){
                    count_char++;
                }
            }
            min_count_char = min(min_count_char, count_char);
        }

        for(int l = 0; l < min_count_char; l++){
            ans.push_back(i);
        }
    }
    
    cout << ans << endl;
   
    return 0;
}