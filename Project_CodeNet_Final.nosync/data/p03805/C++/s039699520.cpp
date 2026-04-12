#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> nodes,edges[10];
    for (int i=2;i<=N;i++) {
        nodes.push_back(i);
    }
    for (int i=0;i<M;i++) {
        int le, ri;
        cin>>le>>ri;
        edges[le].push_back(ri);
        edges[ri].push_back(le);
    }
    
    int ans=0, donecou, nodenum;
    do {
        nodenum=1;
        donecou=0;
        for (int oi=0;oi<nodes.size();oi++) {
            bool flag=false;
            for (int i=0;i<edges[nodenum].size();i++) {
                if (edges[nodenum][i]==nodes[oi])
                    flag=true;
            }
            if (!flag)
                break;
            nodenum=nodes[oi];
            donecou++;
        }
        if (donecou==nodes.size())
            ans++;
    } while(next_permutation(nodes.begin(), nodes.end() ));
    
    cout<<ans<<endl;
    
    return 0;
}
