//#include <stdio.h>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string ans = "";
    string s;
    string a;
    int j1;
    int j2;
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sort(a.begin(), a.end());
        if (i != 0)
        {
            i1 = 0;
            i2 = 0;
            j1 = a.size() - 1;
            j2 = s.size() - 1;

            while (a.size() > i1)
            {
                //if(j2=-1){
                  //  a="";
                 //   break;
                //}
                // cout <<i1<<" "<<i2<<endl;
                //    cout << a.at(i1)<<"  "<< s.at(i2)<<endl;
                //  cout <<a<<"  "<<s<<endl;
                if (a.at(i1) > s.at(i2))
                {

                    i2++;
                    if (j2 < i2)
                    {
                        //while (a.size() > i1){
                        a.erase(i1);

                        //}
                    }
                }
                else if (a.at(i1) < s.at(i2))
                {

                    a.erase(i1, 1);
                }
                else
                {
                    i1++;
                    i2++;
                    if (j2 < i2)
                    {
                        //while (a.size() > i1){
                        a.erase(i1);

                        //}
                    }
                }
                // cout<<a<<endl;
            }
        }
        s = a;
        if(s==""){
            cout <<"" <<endl;
            return 0;
        }
    }
    cout << s << endl;

    return 0;
}
