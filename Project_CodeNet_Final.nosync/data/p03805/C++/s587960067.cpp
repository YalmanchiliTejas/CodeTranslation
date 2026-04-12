#include<iostream>
#include <vector>
#include <numeric>

using namespace std;


int countRoots(vector<int> l, const vector<vector<int> >& em, int pos){
    int count = 0;
    if(l.size()==0) return 1;
    for(int i=0; i!= l.size(); i++){
        if(em[l.at(i)][pos]|| em[pos][l.at(i)]){
            vector<int> newl(l);
            newl.erase(newl.begin() + i);
            count += countRoots(newl, em, l.at(i));
        }
    }
    return count;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > em(N, vector<int>(N, 0));
    int t1, t2;
    for(int i=0; i!=M; i++){
        cin >> t1 >> t2;
        em.at(t1-1).at(t2-1)++;
    } 
    vector<int> left(N-1);
    iota(left.begin(), left.end(), 1);
    cout << countRoots(left, em, 0) << endl;
    return 0;
}