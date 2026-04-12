#include<iostream>
#include<string>
using namespace std;
bool check(string s){
    int n = s.size();
    if(s[0] == '0'){
        if(n > 1)return false;
        else return true;
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        num *= 10;
        num += s[i]-'0';
    }
    if(num > 255)return false;
    return true;
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                //[0,i)[i,j)[j,k)[k,n)
                if(check(s.substr(0,i)) && check(s.substr(i,j-i))
                    && check(s.substr(j,k-j)) && check(s.substr(k))){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

