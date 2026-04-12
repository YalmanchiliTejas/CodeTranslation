#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <utility>
#include <time.h>
#include <set>
#include <unordered_set>
#include <list>
#include <iterator>
#include <time.h>
#include <chrono>
#include <deque>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <tuple>
#include <map>
#include <cassert>
#include <bitset>
using namespace std;

#define ll long long
#define ldb long double
const ll M = 1e9 + 7;

ll mod(ll a, ll b)
{
	return (b + (a % b)) % b;
}

ll addMod(ll a, ll b)
{
	return ((a % M) + (b % M)) % M;
}

ll addMod(ll a, ll b, ll m)
{
	return ((a % m) + (b % m)) % m;
}

ll mulMod(ll a, ll b)
{
	return ((a % M) * (b % M)) % M;
}

ll mulMod(ll a, ll b, ll m)
{
	return ((a % m) * (b % m)) % m;
}

ll subMod(ll a, ll b)
{
	return mod((mod(a, M) - mod(b, M)), M);
}

ll subMod(ll a, ll b, ll m)
{
	return mod((mod(a, m) - mod(b, m)), m);
}

ll dayofweek(ll d, ll m, ll y)
{
	static ll t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 +
		y / 400 + t[m - 1] + d) % 7;
}

//ll nCr(ll n, ll r)
//{
//	ll* C = new ll[r + 1];
//
//	for (ll i = 0; i <= r; i++)
//	{
//		C[i] = 0;
//	}
//
//	C[0] = 1;
//	for (ll i = 1; i <= n; i++)
//	{
//		for (ll j = min(i, r); j > 0; j--)
//		{
//			C[j] = (C[j] + C[j - 1]) % M;
//		}
//	}
//
//	ll temp = C[r];
//	delete[] C;
//	return temp;
//}
//
//ll nCrLucas(ll n, ll r)
//{
//	if (r == 0) return 1;
//
//	ll ni = n % M, ri = r % M;
//	return (nCrLucas(n / M, r / M) * nCr(ni, ri)) % M;
//}


// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll* x, ll* y);

// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m)
{
	ll x, y; // used in extended GCD algorithm 
	ll g = gcdExtended(b, m, &x, &y);

	// Return -1 if b and m are not co-prime 
	if (g != 1)
		return -1;

	// m is added to handle negative x 
	return (x % m + m) % m;
}

// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m)
{
	a = a % m;
	ll inv = modInverse(b, m);
	/*if (inv == -1)
		cout << "Division not defined";
	else
		cout << "Result of division is " << (inv * a) % m;*/

	return (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
	// Base Case 
	if (a == 0)
	{
		*x = 0, * y = 1;
		return b;
	}

	ll x1, y1; // To store results of recursive call 
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

ll power(ll x, ll y)
{
	ll temp;
	if (y == 0) return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0) return mulMod(temp, temp);
	else return mulMod(x, mulMod(temp, temp));
}

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void HeapRebuild(int arr[], int size, int pos)
//{
//	int value = arr[pos];
//	bool isHeap = false;
//
//	while (isHeap == false && 2 * pos + 1 < size)
//	{
//		int smallerChildIndex = 2 * pos + 1; //First element (On the left)
//
//		if (smallerChildIndex < size - 1) //Has enough 2 elements
//		{
//			int rightChildIndex = 2 * pos + 2; //Second element (On the right)
//
//			//Find the postion of the larger between arr[2 * pos + 1] and arr[2 * pos + 2]
//			if (arr[smallerChildIndex] > arr[rightChildIndex])
//			{
//				smallerChildIndex = rightChildIndex;
//			}
//		}
//
//		if (value <= arr[smallerChildIndex])
//		{
//			isHeap = true;
//		}
//		else
//		{
//			Swap(arr[pos], arr[smallerChildIndex]);
//			pos = smallerChildIndex;
//		}
//	}
//}
//
//void HeapCreate(int arr[], int size)
//{
//	for (int i = size / 2 - 1; i >= 0; i--)
//	{
//		HeapRebuild(arr, size, i);
//	}
//}

ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

void test()
{

}

void solve()
{
	string s;
	cin >> s;
	unordered_set<char> Set;

	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		Set.insert(s[i]);
	}

	if (Set.size() == 2)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//test();
	solve();

	return 0;
}