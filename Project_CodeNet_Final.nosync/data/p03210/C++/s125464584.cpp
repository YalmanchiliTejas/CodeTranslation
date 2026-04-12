#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>

/*
 *変数
 */
int x;

/*
 *解 
 */
void solve(){
    if(x==3||x==5||x==7)printf("YES");
    else printf("NO");
}

/*
 *入力 
 */
int main(){
       std::cin.tie(0);
       std::ios::sync_with_stdio(false);
       std::cin>>x;
       solve();
       return 0;
}