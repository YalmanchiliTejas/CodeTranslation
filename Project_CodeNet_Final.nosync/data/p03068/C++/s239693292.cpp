#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int length,pos;
    cin >> length;
    
    string message;
    cin >> message;
    
    cin >> pos;
    
    string target =  message.substr(pos-1,1);
    
    string ans = "";
    for(int i=0; i<length; i++)
    {
        if(message.substr(i,1) != target)
        {
            ans +="*";
        }
        else
        {
            ans +=target;
        }
    }
    
    cout << ans << endl;
    return 0;
}
