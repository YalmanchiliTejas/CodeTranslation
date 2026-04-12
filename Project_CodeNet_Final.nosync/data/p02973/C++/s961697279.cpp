#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

int main()
{
    vector<int> prevs = {};
    int val;
    int N;
    vector<int>::iterator position;
    int index;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val;

        position = lower_bound(prevs.begin(), prevs.end(), val);
        index = distance(prevs.begin(), position);
  
        if (index == 0){
          prevs.insert(prevs.begin(), val);
        }
        else
        {
          prevs[index - 1] = val;
        }
    }
    cout << prevs.size() << endl;
}
