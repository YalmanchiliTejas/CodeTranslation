#include<iostream>
using namespace std;
bool a[105];
int main(void)
{
    string s[105];
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)
        cin >> s[i];
    for(int i=0;i<w;i++)
    {
        int cnt=0;
        for(int j=0;j<h;j++)
            if(s[j][i]=='.')
                cnt++;
        if(cnt==h) a[i]=false;
        else a[i]=true;
    }
    for(int i=0;i<h;i++)
        if(s[i].find('#')<(int)s[i].size())
        {
            for(int j=0;j<w;j++)
            {
                if(s[i][j]=='#')
                    cout << s[i][j];
                else if(s[i][j]=='.' && a[j]==true)
                    cout << s[i][j];
            }
            cout << endl;
        }
    return 0;
}