#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int rankCount[31]={0};
    int number[100],score[100],count=0;
    while(scanf("%d,%d",&number[count],&score[count]),number[count] || score[count]){
        rankCount[score[count]]++;
        count++;
    }

    int n;
    while(cin>>n){
        int rank=0;
        for(int i=0; i<count; i++){
            if(number[i]==n){
                for(int j=30; j>score[i]; j--){
                    if(rankCount[j]>0){
                        rank++;
                    }
                }
                rank++;
                break;
            }
        }
        cout<<rank<<endl;
    }
    return 0;
}