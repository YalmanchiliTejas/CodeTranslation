#include <bits/stdc++.h>

using namespace std;

int n;
int s[100]={};
int count = 0;
int dai,syou;
int ans[1000]={};
int judge = 0;

int main()
{
    while(1){
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        dai = 0;
        syou = 1000;
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
            if(dai <= s[i]){
                dai = s[i];
            }
            if(syou >= s[i]){
                syou = s[i];
            }
        }
        int dai_count = 0;
        int syou_count = 0;
        for(int i=0;i<n;i++){
            if(s[i]==dai && dai_count ==0){
                dai_count=1;
                
            }else if(s[i] == syou && syou_count ==0){
                syou_count = 1;
            }else{
                ans[judge] += s[i];
            }
        }
        ans[judge] = ans[judge] / (n-2);
        
        judge++;

    }
    for(int i=0;i<judge;i++){
        cout << ans[i] << endl;
    }

    
    return 0;
}
