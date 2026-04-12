#include <iostream>

using namespace std;
char str[10];
int main()
{
    cin>>str;
    for(int i=0;i<2;i++)
    {
        if(str[i]!=str[i+1]){
            cout<<"Yes"<<endl;
            return 0;
        }else{
        }
    }
    cout<<"No"<<endl;
}