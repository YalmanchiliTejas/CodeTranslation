#include <iostream>
using namespace std;
char a[101][101];
int n,m;

void changecol(int pos){
    for (int i=0;i<m;i++)
        a[pos][i]=' ';
}
bool checkcol(){
    for (int i=0;i<n;i++){
        int count=0;
        for (int j=0;j<m;j++){
            if (a[i][j]=='.' || a[i][j]==' ')
                count++;
            if (count==m){
                changecol(i);
            }
        }
        
    }
}
void changerow(int pos){
    for (int i=0;i<n;i++)
        a[i][pos]=' ';
}
void checkrow(){
    for (int i=0;i<m;i++){
        int count=0;
        for (int j=0;j<n;j++){
            if (a[j][i]=='.' || a[j][i]==' ')
                count++;
            if (count==n){
                changerow(i);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    checkcol();
    checkrow();
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<m;j++)
    //         cout<<a[i][j];
    //     cout<<endl;
    // }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]==' ')   continue;
            cout<<a[i][j];
        }
        int count=0;
        for (int j=0;j<m;j++)   if (a[i][j]==' ')   count++;
        if (count<m)   cout<<endl;
    }
    return 0;
}