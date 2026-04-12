#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }

        int dice[6] = {1, 6, 2, 5, 4, 3};
        int ans = 1;
        string s;
        for(int i=0; i<n; i++){
            cin >> s;
            int tmp;
            if(s == "North"){
                tmp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[3];
                dice[3] = tmp;
            }else if(s == "East"){
                tmp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[1];
                dice[1] = dice[5];
                dice[5] = tmp;
            }else if(s == "West"){
                tmp = dice[0];
                dice[0] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[4];
                dice[4] = tmp;
            }else if(s == "South"){
                tmp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[2];
                dice[2] = tmp;
            }else if(s == "Right"){
                tmp = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[4];
                dice[4] = tmp;
            }else if(s == "Left"){
                tmp = dice[2];
                dice[2] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[5];
                dice[5] = tmp;
            }
            ans += dice[0];
        }
        cout << ans << endl;
    }
  
  return 0;
}