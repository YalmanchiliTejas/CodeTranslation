#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string ans;
    string sorw;
    bool flag = true;
    
    for(int i = 1; i <=4  ; i++){
        if(i ==1){
            ans = "WW";
        }else if(i == 2){
            ans = "WS";
        }else if(i == 3){
            ans = "SW";
        }else if(i == 4){
            ans = "SS";
        }
        for(int j = 0 ; j < n ; j++){
            if(ans[j] == 'W' && ans[j+1] == 'W' && s[j] == 'o'){
                sorw = 'S';
            }else if(ans[j] == 'W' && ans[j+1] == 'W' && s[j] == 'x'){
                sorw = 'W';
            }else if(ans[j] == 'W' && ans[j+1] == 'S' && s[j] == 'o'){
                sorw = 'W';
            }else if(ans[j] == 'W' && ans[j+1] == 'S' && s[j] == 'x'){
                sorw = 'S';
            }else if(ans[j] == 'S' && ans[j+1] == 'W' && s[j] == 'o'){
                sorw = 'W';
            }else if(ans[j] == 'S' && ans[j+1] == 'W' && s[j] == 'x'){
                sorw = 'S';
            }else if(ans[j] == 'S' && ans[j+1] == 'S' && s[j] == 'o'){
                sorw = 'S';
            }else if(ans[j] == 'S' && ans[j+1] == 'S' && s[j] == 'x'){
                sorw = 'W';
            }
            
            ans += sorw;
            }
            if(ans[0] == ans[ans.size()-2] && ans[1] == ans[ans.size()-1]){
                //cout << "Break!" << endl;
                flag = false;
                ans = ans.substr(1);
                ans = ans.erase(ans.size()-1,1);
                break;
            }
    }
    if(flag){
        cout << "-1" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}