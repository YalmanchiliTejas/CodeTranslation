#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int counter = 0;
void findP(vector<int> points);
int n, m;
vector<pair<int, int>> edge;

int main()
{
#ifdef LOCAL
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int p1, p2;
        cin >> p1 >> p2;
        edge.push_back({p1, p2});
    }

    vector<int> points = {1};
    findP(points);

    cout << counter << endl;

    return 0;
}
void findP(vector<int> points){
    if(points.size() >= n){
        counter++;
    }
    else{
        for(auto iter:edge){
            vector<int> tmpPoint = points;
            if(iter.first == tmpPoint[points.size()-1] && std::count(tmpPoint.begin(), tmpPoint.end(), iter.second) == 0){
                tmpPoint.push_back(iter.second);
                findP(tmpPoint);
            }
            else if(iter.second == tmpPoint[points.size()-1] && std::count(tmpPoint.begin(), tmpPoint.end(), iter.first) == 0){
                tmpPoint.push_back(iter.first);
                findP(tmpPoint);
            }
        }
    }
}