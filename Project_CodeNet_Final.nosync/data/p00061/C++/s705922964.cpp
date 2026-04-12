#include<bits/stdc++.h>
using namespace std;
int main()
{
    int team[200],num=0,point,lank[200],co=0,flag=0;
    queue<int> que;
    string str;
    for(int i=1;i<200;i++)team[i]=-1;
    while(cin>>str){
        if(str[0]=='0'&&str[2]=='0')break;
        for(int i=0;;i++){
            if(str[i]==','){
                for(int j=0;j<i;j++)num+=(str[j]-'0')*(int)pow(10,i-j-1);
                team[num]=0;
                point=i;
            }
            else if(str[i]=='\0'){
                for(int j=point+1;j<i;j++)team[num]+=(str[j]-'0')*pow(10,i-j-1);
                break;
            }
        }
        num=0;
    }
    point=0;
    for(int i=1;flag!=1;i++){
        flag=1;
        for(int j=1;j<200;j++){
            if(point<team[j]){
                flag=0;
                point=team[j];
                if(co!=0){
                    for(int k=0;k<co;k++)que.pop();

                }
            co=1;
            que.push(j);
            }
            else if(point==team[j]){
                    flag=0;
                    que.push(j);
                    co++;
            }
        }
        for(int j=0;j<co;j++){
            lank[que.front()]=i;
            team[que.front()]=-1;
            que.pop();
        }
        point=0;co=0;
    }
    while(cin>>num)cout<<lank[num]<<endl;

}