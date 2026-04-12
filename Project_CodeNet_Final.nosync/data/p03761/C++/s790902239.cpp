#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    string a, s;
    vector<string> str;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        str.emplace_back(a);
    }
    
    
    for(int i = 'a'; i <= 'z'; i++)
    {
        int cmin = 1000;
        for(int j = 0; j < n; j++)
        {
            int sum = 0;
            for(int o = 0; o < str[j].size(); o++)
            {
                if(str[j][o] == i)
                {
                    sum++;
                }
            }
            
            if(sum <= cmin)
            {
                cmin = sum;
            }
        }
        for(int b = 0; b < cmin; b++)
            
        {
            s += i;
        }

    }
    
    cout << s << endl;
}