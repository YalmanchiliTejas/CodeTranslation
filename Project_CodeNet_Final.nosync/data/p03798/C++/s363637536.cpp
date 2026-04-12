#include <bits/stdc++.h>
using namespace std;
 
bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}
 
long long n;
string s;
int ans[100002];
bool flag = false;

int main(){
    cin >> n >> s;
    int are0[4] = {1,1,-1,-1}, are1[4] = {1,-1,1,-1};

    for(int i = 0; i < 4; i++){
        ans[0] = are0[i];
        ans[1] = are1[i];

        for(int j = 1; j < n; j++){
            if(s[j] == 'o'){
                if(ans[j] == 1) ans[j+1] = ans[j-1];
                else    ans[j+1] = -1 * ans[j-1];
            }
            else{
                if(ans[j] == 1) ans[j+1] = -1 * ans[j-1];
                else    ans[j+1] = ans[j-1];
            }
        }

        flag = ans[0] == ans[n];
        if(flag){
            if(s[0] == 'o'){
                if(ans[0] == 1) flag = ans[1] == ans[n-1];
                else    flag = ans[1] != ans[n-1];
            }
            else{
                if(ans[0] == 1) flag = ans[1] != ans[n-1];
                else    flag = ans[1] == ans[n-1];                
            }
        }

        if(flag){
            for(int j = 0; j < n; j++){
                if(ans[j] == 1) cout << 'S';
                else    cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << "-1\n";
}