#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string name[1000],nmemo;
    int n,a,b,c,num=0,score[1000];
    while(1){
        num++;
    cin>>n;
        if(n==0){
            break;
        }
        if(num!=1){
            cout<<endl;
        }
    for(int i=0;i<n;i++){
        cin>>name[i]>>a>>b>>c;
        score[i]=a*3+c;
    }
    int max=-10000,count=0,j=0,s;bool bo=false;
    while(1){
        if(count==n){
            break;
        }
        for(int i=0;i<n;i++){
            if(score[i]>max){
                max=score[i];
                s=i;
            }
        }
        cout<<name[s]<<","<<score[s]<<endl;
        count++;
        score[s]=-10;
        max=-10000;
    }
    }
    return 0;
}