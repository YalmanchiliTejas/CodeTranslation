#include<iostream>
#include<set>
#include<map>

using namespace std;
typedef pair<int,int> pp;


int main()
{
    int point,num;
    char t;
    multiset<pp,greater<pp> > plist;
    while(cin >> num >> t >> point )
    {
        if(num==0&&point ==0)break;
        plist.insert(pp(point,num));
    }
    while(cin >> num)
    {
        int juni=1;
        int nowpoint = (*(plist.begin())).first;
        for(multiset<pp>::iterator it = plist.begin();it!=plist.end();++it)
        {
            if(nowpoint!=(*it).first)
            {
                juni+= 1;
                nowpoint = (*it).first;
            }
            if(num==(*it).second)
            {
                cout << juni << endl;
                break;
            }

        }
    }

    return 0;
}