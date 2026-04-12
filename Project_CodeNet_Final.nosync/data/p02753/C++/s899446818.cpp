#include <iostream>

using namespace std;

int main()
{
    char S,yes=0,no=0;
    for(int i=0;i<3;i++){
        cin>>S;
        if(S=='A')
            yes++;
        else if(S=='B')
            no++;
    }
    if(yes==3 || no==3)
        cout<<"No"<<endl;
    else
        cout<<"Yes";

    return 0;
}
