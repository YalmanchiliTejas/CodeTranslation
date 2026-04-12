#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>

#define REP(i,n) for(int i=0;i<(n);i++)

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int main(){
    string str;
    string left = "qwertasdfgzxcvb";
    string right = "yuiophjklnm";

    while(true){
        cin >> str;
        if(str=="#") break;
        int cnt = 0;
        bool on_right = true;
        REP(i,str.size()){
            if(on_right){
                REP(j,left.size()){
                    if(str[i] == left[j]){
                        on_right = false;
                        cnt++;
                        if(i==0) cnt--;
                    }
                }
            }else{
                REP(j,right.size()){
                    if(str[i] == right[j]){
                        on_right = true;
                        cnt++;
                        if(i==0) cnt--;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}