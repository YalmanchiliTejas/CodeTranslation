#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
char arr[10];
int main()
{
    scanf("%s",arr);
    if(arr[0]==arr[1]&&arr[1]==arr[2])
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
