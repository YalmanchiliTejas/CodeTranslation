#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
        int i,j;
        string s;
        int k;
        int n[200];
        int x;

        cin >> s;
        cin >> k;

        long long ans=0;
        int a; //����
        a = s.length();

        for(i=0;i<a;i++){
                n[i] = s[i]-'0';
        }

        if(k==3){
                ans += 9*9*9*(a-1)*(a-2)*(a-3)/6;
                ans += 9*9*(n[0]-1)*(a-1)*(a-2)/2;
                x=1;
                
                while(x<a && n[x]==0){
                        x++;
                }
                if(x==a){
                        printf("%lld\n",ans);
                        return 0;
                }
                for(i=x;i<a;i++){
                        n[i-x]=n[i];
                }
                a = a-x;
                k--;
        }

        if(k==2){
                ans += 9*9*(a-1)*(a-2)/2;
                ans += 9*(n[0]-1)*(a-1);
                x=1;
                while(x<a && n[x]==0){
                        x++;
                }
                if(x==a){
                        printf("%lld\n",ans);
                        return 0;
                }
                for(i=x;i<a;i++){
                        n[i-x]=n[i];
                }
                a=a-x;
                k--;
        }

        if(k==1){
                ans += 9*(a-1);
                ans += n[0];
        }
        printf("%lld\n",ans);
        return 0;
}

