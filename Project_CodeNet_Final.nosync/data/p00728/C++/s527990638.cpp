#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> scores;
int judge;

int main()
{
        while(cin >> N){
                if(N==0) break;
                int sum = 0;
                for(int i=0;i<N;i++){
                        cin >> judge;
                        scores.push_back(judge);
                }

                sort(scores.begin(),scores.end());
                scores.erase(scores.begin());
                scores.erase(scores.end()-1);
                for(int i=0;i<N-2;i++){
                        sum += scores[i];
                }
                cout << sum/scores.size() << endl;
                scores.clear();
        }

        return 0;
}