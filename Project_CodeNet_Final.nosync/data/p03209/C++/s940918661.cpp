#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  ull unsigned long long
#define  ul unsigned long
#define all(v) v.begin(),v.end()
#define sz(n) (int)n.size()
#define pb(s) push_back(s);
#define format(n) fixed<<setprecision(n)
#define finl "\n"
#define Mohammed_Atef_Hassan fast();
#define INF LLONG_MAX
#define PI acos(-1)
#define clr(dp,n) memset(dp,n,sizeof dp)
#define ex(n) return cout<<n<<finl,0;
#define N (int)1e6+10
int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
void fast() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

#ifdef ONLINE_JUDGE
	//	freopen("palindrome.in", "r", stdin);

	//freopen("palindrome.out", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
	//freopen("9000000.txt", "r", stdin);

	//freopen("ConsoleApplication1.zip", "w", stdout);
#endif
}
// create Node
class node
{
public:
	 int data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
};

class LinkedList
{
private:
	node* Head;
public:
	LinkedList()
	{
		Head = NULL;
	}

	void InsertItem(int d)
	{
		node* n=new node; // create new node
		n->data = d;
		if (Head == NULL)
		{
			Head = n;
			n->next = NULL;
		}

		else
		{
			node* t = Head;
			while (t->next != NULL)
				t = t->next;
			t->next = n;
			n->next = NULL;
		}
	}

	void DeleteItem(int d)
	{
		node* c = Head;
		node* p=NULL;
		if (c != NULL && c->data == d)
		{
			Head = Head->next;
			return;
		}
		while (c != NULL)
		{
			if (c->data == d)
				break;
			p = c;
			c = c->next;
		}
		if (c != NULL)
		{
			p->next = c->next;
		}
		else
		{
			cout << "Not Found" << endl;
		}

	}

	void PrintItem()
	{
		node* t = Head;
		cout << "Items:" << endl;
		while (t != NULL)
		{
			cout << t->data << "  ";
			t = t->next;
		}
		cout << endl;
	}

};

int main()
{
	Mohammed_Atef_Hassan
		/*	LinkedList s;
		s.InsertItem(1);
		s.InsertItem(2);
		s.PrintItem();
		s.DeleteItem(1);
		s.PrintItem();*/
		pair<ll,ll>arr[51];
	arr[0] = { 1,1 };
	for (int i = 1; i <= 50; i++)
	{
		arr[i] = { arr[i - 1].first*2 + 3,arr[i - 1].second*2 + 1 };
	}
	int n; ll k; ll cnt = 0;
	cin >> n >> k;
	while (n>=0)
	{
		int i = n;
		while (k < arr[i].first)
		{
			k--; i--;
		}
		if (i < 0)break;
		cnt += arr[i].second;
		k -= arr[i].first;
		if (k <= 0)break;
		if (k > 0)
		{
			k--; cnt++;
		}
		n = i;
	}
	cout << cnt << finl;
}