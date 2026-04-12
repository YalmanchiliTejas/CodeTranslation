#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Problem
{
private:
	// Variables
	int r, g, b;
	
public:
	// Methods
	void input ()
	{
		cin >> r >> g >> b;
	}
	
	void process ()
	{
		
	}
	
	void output ()
	{
		cout << ((g*10 + b & 3) ? "NO" : "YES") << endl;
	}
};

int main ()
{
	Problem problem;
	problem.input();
	problem.process();
	problem.output();
	return 0;
}