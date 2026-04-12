#include <iostream>
#include <vector>

using namespace std;

int main()
{
  	int N;
  	cin >> N;
  
  	int nWatch = 0;
  	vector<int> Hotels;
  	for(int i = 0; i < N; ++ i)
    {
      	bool canWatch = true;
      	int nHigh;
      	cin >> nHigh;
      
      	for( int j = 0; j < i; ++ j)
        {
        	if(nHigh < Hotels[j])
            {
            	canWatch = false;
              	break;
            }
        }
      
      	if(canWatch)
          ++nWatch;
      	
      	Hotels.push_back(nHigh);
    }
  
  	cout << nWatch;
	return 0;
}