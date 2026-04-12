#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N;
    cin>>N;

    multiset<int> S;
    for (int i=0; i<N; i++)
    {
        int A;
        cin>>A;

        multiset<int>::iterator p = S.lower_bound(A);
        if (p!=S.begin())
        {
            p--;
            S.erase(p);
        }
        S.insert(A);
    }
    cout<<S.size()<<endl;
}
