#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

void input(vector<int> & V);

int main()
{
    vector<int> V;
    input(V);

    //法1

    int q, k;
    cin >> q;

    while (q--)
    {
        cin >> k;
        // vector<int>::iterator it = V.begin();
        // while (*it < k && it != V.end()) 
        // {
        //     it++;
        // }
        // if (it != V.end())
        //     cout << distance(V.begin(), it);
        // else 
        //     cout << V.size();

        //也可以循环体中根据条件break
        // while (it != V.end())
        // {
        //     if (*it >= k)
        //         break;
        //     it++;
        // }
        cout << lower_bound(V.begin(), V.end(), k) - V.begin() << endl;    



    }

}

void input(vector<int> & V)
{
    int n;
    cin >> n;

    int a;
    while (n--)
    {
        cin >> a;
        V.push_back(a);
    }
}
