#include<bits/stdc++.h>
using namespace std;
int w[100010],b[100010],n,a,ans,tasu;

int main(){

    while(1){

    cin >> n;
    if(n==0)break;
    cin >> a;
    if(a==0){
        w[1]=1;
    }else{
        b[1]=1;
    }
    //printf("i=1 b=%d w=%d\n",b[1],w[1]);

    for(int i=2;i<=n;i++){
        cin >> a;
        if(i%2==0){
            if(a==1){
                if(w[i-1]>0){
                    b[i]=w[i-1]+1;
                    w[i-1]=0;
                    //printf(" b[i-b[i]]=%d\n b[i]=%d\n",b[i-b[i]],b[i]);

                    tasu=b[i-b[i]];
                    b[i-b[i]]=0;
                    b[i]+=tasu;
                }else if(b[i-1]>0){
                        b[i]=b[i-1]+1;
                        b[i-1]=0;
                    }else {
                        b[i]++;
                    }
            }else{
                if(b[i-1]>0){
                    w[i]=b[i-1]+1;
                    b[i-1]=0;
                    //printf("w[i-w[i]]=%d\n",w[i-w[i]]);
                    tasu=w[i-w[i]];
                    w[i-w[i]]=0;
                    w[i]+=tasu;
                }else if(w[i-1]>0){
                        w[i]=w[i-1]+1;
                        w[i-1]=0;
                    }else {
                        w[i]++;
                    }

            }
        }else{
            if(a==1){
                if(b[i-1]>0){
                    b[i]=b[i-1]+1;
                    b[i-1]=0;
                }else b[i]++;
            }else{
                if(w[i-1]>0){
                    w[i]=w[i-1]+1;
                    w[i-1]=0;
                }else w[i]++;

            }
        }
        //printf("i=%d b=%d w=%d\n",i,b[i],w[i]);
    }

    for(int i=1;i<=n;i++){
   //     cout << w[i] << endl;
  //  printf("i=%d b=%d w=%d\n",i,b[i],w[i]);
        if(w[i]>0)ans+=w[i];
    }

    cout << ans << endl;

    ans=0;
    for(int i=0;i<=n;i++){
        b[i]=0;
        w[i]=0;
    }

    }


return 0;
}