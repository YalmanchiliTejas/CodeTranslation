#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int p;
    int s;
    char ch;
    std::set<int> st;
    int q;
    vector<int> vec;
    while(1)
    {
        cin >> p >> ch >> s;
        if(p == 0 && s == 0)
        {
            break;
        }
        vec.push_back(s);
    }
    for(int i=0; i<vec.size(); i++)
    {
        st.insert(vec[i]);
    }

    while(cin >> q)
    {
        auto itr = st.find(vec[q - 1]);
        cout << std::distance(itr, st.end()) << endl;
    }
    return 0;
}

