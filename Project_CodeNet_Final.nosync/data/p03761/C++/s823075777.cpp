#include <bits/stdc++.h>

using namespace std;
int can[30];
int main(){
    for(int i =0; i < 30; i++) can[i]=0;
    int n;
    cin >> n;
    for(int i =0;i <n;i++){
        string st;
        cin >> st;
        int arr[30];
        for(int e = 0; e < 30; e++){
            arr[e]=0;
        }
        for(int e = 0; e <st.length(); e++){
            if(i == 0){
                can[st[e]-'a']++;
            }else
            arr[st[e]-'a']++;
        }
        if(i==0)continue;
        for(int e = 0; e <30; e++){
            can[e] = min(can[e],arr[e]);
        }
    }
    string ans="";
    for(int i = 0; i < 30; i++){
        for(int e = 0; e < can[i]; e++){
             //   cout << "ASD";
            ans+=i+'a';
        }
    }
    cout << ans;
    return 0;
}
