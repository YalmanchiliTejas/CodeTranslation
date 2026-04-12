#include  <iostream>
#include  <stdio.h>
using namespace std;




int main(){

    int N;
    int K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;

    string tar;
    string tar_x;
    string ans;
    ans = "";
    tar = S.substr(K-1,1);
    for( int ni = 0 ; ni < N ; ni++ ){
        tar_x = S.substr(ni,1);
        if(tar == tar_x){
            ans = ans + tar;
        }else{
            ans = ans + "*";
        }
    }
    cout << ans;
}