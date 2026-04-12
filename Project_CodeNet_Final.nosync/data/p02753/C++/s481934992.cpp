#include<bits/stdc++.h>
using namespace std;
char s[3];
int main()
{
        for(int i = 0; i< 3; i++)
        {
                cin >> s[i];
        }
        if(s[0] == s[1]&&s[0]== s[2]&&s[1] == s[2])
        {
                cout<< "No" << endl;
        }
        else{

          cout << "Yes"<< endl;
        }
}
