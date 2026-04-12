#include <iostream>
using namespace std;

int n;
char s[100003];

bool check(bool first, bool second){
    bool is_sp[100001] = {0, first, second};
    if(first){
        if(s[1] == 'o'){
            is_sp[0] = second;
        }else{
            is_sp[0] = !second;
        }
    }else{
        if(s[1] == 'o'){
            is_sp[0] = !second;
        }else{
            is_sp[0] = second;
        }
    }
    
    int i;
    for(i = 2; i < n; i++){
        if(is_sp[i]){
            if(s[i] == 'o'){
                is_sp[i + 1] = is_sp[i - 1];
            }else{
                is_sp[i + 1] = !is_sp[i - 1];
            }
        }else{
            if(s[i] == 'o'){
                is_sp[i + 1] = !is_sp[i - 1];
            }else{
                is_sp[i + 1] = is_sp[i - 1];
            }
        }
    }
    
    if(is_sp[0] != is_sp[n]){
        return false;
    }
    
    if(is_sp[n]){
        if(!((s[n] == 'o' && is_sp[1] == is_sp[n - 1]) || (s[n] == 'x' && is_sp[1] != is_sp[n - 1]))){
            return false;
        }
    }else{
        if(!((s[n] == 'o' && is_sp[1] != is_sp[n - 1]) || (s[n] == 'x' && is_sp[1] == is_sp[n - 1]))){
            return false;
        }
    }
    
    for(i = 1; i <= n; i++){
        if(is_sp[i]){
            cout << "S";
        }else{
            cout << "W";
        }
    }
    cout << endl;
    return true;
}

int main(void){
    cin >> n;
    cin >> &s[1];
    
    if(check(true, true)){
        return 0;
    }else if(check(true, false)){
        return 0;
    }else if(check(false, true)){
        return 0;
    }else if(check(false, false)){
        return 0;
    }
    
    cout << -1 << endl;
    
    return 0;
}
