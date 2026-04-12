#include <iostream>
#include <string>
using namespace std;
int main()
{
    string st;
    cin>>st;
    int x=st.find("AC");
    if(x>=0&&x<st.length())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
