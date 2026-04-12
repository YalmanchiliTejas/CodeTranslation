#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> vec;
long long in;
long long out[110100];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> in;
		vec.push_back(in);
	}
	sort(vec.begin(), vec.end());

	int index = n / 2;
	index -= ((n % 2) == 0);
	int left = index - 1;
	int right = index + 1;
	int endIndex = vec.size() - 1;
	int startIndex = 1;
	out[index] = vec[0];
	for (int i = 0; i < n / 2 - 1; i++)
	{
		if ((i % 2) == 0)
		{
			out[left] = vec[endIndex--];
			out[right] = vec[endIndex--];
			left--;
			right++;
		}
		else
		{
			out[right] = vec[startIndex++];
			out[left] = vec[startIndex++];
			left--;
			right++;
		}
		/*for (int j = 0; j < n; j++)
		{
			cout << out[j];
		}
		cout << endl;*/
	}
	if ((n % 2) == 0)
	{
		out[right] = vec[startIndex++];
	}
	else
	{
		out[right] = vec[startIndex++];
		out[left] = vec[startIndex++];

	}
	long long sum = 0;

	for (int i = 0; i < n - 1; i++)
	{
		sum += abs(out[i] - out[i + 1]);
		//cout << out[i];
	}

	for (int i = 0; i < n; i++)
	{
		out[i] = 0;
	}

	index = n / 2;
	left = index - 1;
	right = index + 1;
	endIndex = vec.size() - 1;
	startIndex = 0;
	out[index] = vec[endIndex--];
	for (int i = 0; i < n / 2 - 1; i++)
	{
		if ((i % 2) == 0)
		{
			out[left] = vec[startIndex++];
			out[right] = vec[startIndex++];
			left--;
			right++;
		}
		else
		{
			out[left] = vec[endIndex--];
			out[right] = vec[endIndex--];
			left--;
			right++;
		}

	}
	if ((n % 2) == 0)
	{
		out[left] = vec[endIndex--];
	}
	else
	{
		
		out[left] = vec[endIndex--];
		out[right] = vec[endIndex--];

	}
	long long sum2 = 0;
	/*for (int i = 0; i < n; i++)
	{
		cout << out[i];
	}*/
	for (int i = 0; i < n - 1; i++)
	{
		sum2 += abs(out[i] - out[i + 1]);
		//cout << out[i];
	}
	if (sum >= sum2)
	{
		cout << sum;
	}
	else
	{
		cout << sum2;
	}

	


	return 0;
}