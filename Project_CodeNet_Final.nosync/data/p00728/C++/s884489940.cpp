#include <iostream>
using namespace std;

int main()
{
	int N, n, sum, largest, smallest;
	
	while(cin >> N && N>0){
		sum  = 0; largest = 0; smallest = 1000;
		for(int i = 0; i<N; i++)
		{
			cin >> n;
			sum += n;
			
			if(smallest > n){ smallest = n;}
			if(largest < n){ largest = n;}
		}
	
		cout << (sum-smallest-largest)/(N-2) << endl;
	}
}
