#include<iostream>
using namespace std;
int dice[6];
void exswap(int a,int b,int c,int d){
    int work;
    work=dice[a];
    dice[a]=dice[b];
    dice[b]=dice[c];
    dice[c]=dice[d];
    dice[d]=work;
}
int main(){
    int n;
    while(cin>>n,n){
        for(int i=0;i<6;i++)dice[i]=i+1;
        int sum=0;
        while(n--){
            string str;
            cin>>str;
            if(str=="North")exswap(0,1,5,4);
            else if(str=="East")exswap(0,3,5,2);
            else if(str=="West")exswap(0,2,5,3);
            else if(str=="South")exswap(0,4,5,1);
            else if(str=="Right")exswap(1,2,4,3);
            else exswap(1,3,4,2);
            sum+=dice[0];
        }
        cout<<sum+1<<endl;
    }
    return 0;
}