#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int N;
   cin >> N;
   vector<int> H(N);
   for(int i=0;i<N;++i) cin >> H[i];

   int answer = 0;
   int max = 0;

   for(int i=0;i<N;++i){
      if(H[i]>=max){
         max = H[i];
         answer++;
      }
   }

   cout << answer << endl;

   return 0;
}
