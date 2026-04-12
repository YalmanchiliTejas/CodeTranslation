#include<bits/stdc++.h>
using namespace std;
vector<int> vi;
vector<int> :: iterator vit;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int x,y,i,j,a,b;
    cin>>x>>y;
    char str[x][y],str2[100][100],str3[100][100],str4[100][100],str5[100][100];

    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            cin>>str[i][j];
        }
    }
    int cnt=0,k=0;
    for(i=0;i<x;i++){
        cnt=0;
        for(j=0;j<y;j++){
            if(str[i][j]=='.'){
                cnt++;
            }
            else{
                cnt=0;
                break;
            }
        }
        if(cnt==y){

        }
        else{
            for(j=0;j<y;j++){
                str2[k][j]=str[i][j];
            }
            k++;
            cnt=0;
        }
    }
    /*
    cout<<k<<" "<<y<<endl;
    for(i=0;i<k;i++){
        for(j=0;j<y;j++){
            cout<<str2[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    a=0;
    b=0;
    for(i=y-1;i>=0;i--){
        b=0;
        for(j=k-1;j>=0;j--){
            str3[a][b]=str2[j][i];
            b++;
        }
        a++;
    }
    /*
    cout<<a<<" "<<b<<endl;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            cout<<str3[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    */
    cnt=0;
    k=0;
    for(i=0;i<a;i++){
        cnt=0;
        for(j=0;j<b;j++){
            if(str3[i][j]=='.'){
                cnt++;
            }
            else{
                cnt=0;
                break;
            }
        }
        if(cnt==b){

        }
        else{
            for(j=0;j<b;j++){
                str4[k][j]=str3[i][j];
            }
            k++;
        }
    }
    /*
    cout<<k<<" "<<b<<endl;
    for(i=0;i<k;i++){
        for(j=0;j<b;j++){
            cout<<str4[i][j];
        }
        cout<<endl;
    }
    */
    x=a;
    y=b;
    a=0;
    b=0;
    for(i=y-1;i>=0;i--){
        b=0;
        for(j=k-1;j>=0;j--){
            str5[a][b]=str4[j][i];
            b++;
        }
        a++;
    }
    //cout<<a<<" "<<b<<endl;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            cout<<str5[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
