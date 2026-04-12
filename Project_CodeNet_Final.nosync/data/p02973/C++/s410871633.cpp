#include <iostream>
#include <set>
using namespace std;

int main(void){
    int N, Abuf;
    multiset<int> Aset;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> Abuf;
        multiset<int>::iterator AbufinAset = Aset.lower_bound(Abuf);
        if(AbufinAset != Aset.begin())Aset.erase(--AbufinAset);
        Aset.insert(Abuf);
    }

    cout << Aset.size() << endl;

    return 0;
}