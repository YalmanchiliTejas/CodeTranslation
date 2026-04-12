#include<iostream>
using namespace std;
int main()
{
int X,Y,Z;
    cin>>X>>Y>>Z;
    int answer=-1;
    for(int i=0;i<=X-Z;i+=(Z+Y))
        answer++;
    printf("%d",answer);
    return 0;
}