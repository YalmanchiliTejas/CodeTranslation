#include<bits/stdc++.h>
using namespace std;


string s;
int k;
int ans;

int main(){
    
    cin >> s;
    cin >> k;
    int n = s.size();
    for(int i=0;i<n;i++){
        for(int d=1;d<=9;d++){
            if(i==0 and d > s[i]-'0')
                continue;
            bool less1 = i || d < s[i]-'0';
            if(k==1){
                ans++;
            }else{
                for(int j=i+1;j<n;j++){
                    for(int d=1;d<=9;d++){
                        if(!less1 and d > s[j]-'0')
                            continue;
                        bool less2 = less1 || d < s[j]-'0';
                        if(k==2){
                            ans++;
                        }else{
                            for(int k=j+1;k<n;k++){
                                for(int d=1;d<=9;d++){
                                    if(!less2 and d > s[k]-'0')
                                        continue;
                                    ans++;
                                }
                                if(s[k] > '0')
                                    less2 = 1;
                            }
                        }
                    }
                    if(s[j] > '0')
                        less1 = 1;
                }
            }
        }
    }
    cout << ans ;
    
    return 0;
}