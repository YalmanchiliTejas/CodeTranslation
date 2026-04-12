#include <bits/stdc++.h>
using namespace std;

#define NIL (Node *)-1

struct Node {
	int key, priority;
	Node *p, *left, *right;
	Node( int k, int pr ) { key = k; priority = pr; p = left = right = NIL; }
};
Node *root = NIL;

Node *rightRotate( Node *t )
{
	Node *s = t->left;
	t->left = s->right;
	s->right = t;
	return s;
}

Node *leftRotate( Node *t )
{
	Node *s = t->right;
	t->right = s->left;
	s->left = t;
	return s;
}

Node *insert( Node *t, int k, int pr, int f )
{
	if( t == NIL ) {
		Node *n = new Node( k, pr );
		if( f ) {
			root = n;
		}
		return n;
	}
	if( k == t->key ) return t;
	if( k < t->key ) {
		t->left = insert( t->left, k, pr, 0 );
		if( t->priority < t->left->priority ) {
			t = rightRotate( t );
			if( f ) root = t;
		}

	}
	else {
		t->right = insert( t->right, k, pr, 0 );
		if( t->priority < t->right->priority ) {
			t = leftRotate( t );
			if( f ) root = t;
		}
	}
	return t;
}

Node *find( int k )
{
	Node *t = root;
	while( t != NIL ) {
		if( t->key == k ) {
			return t;
		}
		if( k < t->key ) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
	return NIL;
}

Node *_del( Node *t, int k );
Node *del( Node *t, int k, int f )
{
	if( t == NIL ) return NIL;
	if( k < t->key ) t->left = del( t->left, k, 0 );
	else if( k > t->key ) t->right = del( t->right, k, 0 );
	else {
		Node *n = _del( t, k );
		if( f ) root = n;
		t = n;
	}
	return t;
}

Node *_del( Node *t, int k )
{
	if( t->left == NIL && t->right == NIL ) return NIL;
	if( t->left == NIL ) {
		t = leftRotate( t );
	}
	else if( t->right == NIL ) {
		t = rightRotate( t );
	}
	else {
		if( t->left->priority > t->right->priority ) {
			t = rightRotate( t );
		}
		else {
			t = leftRotate( t );
		}
	}
	return del( t, k, 0 );
}

void printp( Node *u )
{
	if( u == NIL ) return;
	cout << " " << u->key;
	printp( u->left );
	printp( u->right );
}

void printm( Node *u )
{
	if( u == NIL ) return;
	printm( u->left );
	cout << " " << u->key;
	printm( u->right );
}

int main()
{
	int m;
	cin >> m;
	for( int i = 0; i < m; i++ ) {
		string com;
		cin >> com;
		if( com == "insert" ) {
			int k, pr;
			cin >> k >> pr;
			insert( root, k, pr, 1 );
		}
		else if( com == "print" ) {
			printm( root );
			cout << endl;
			printp( root );
			cout << endl;
		}
		else if( com == "find" ) {
			int k;
			cin >> k;
			string ans = "no";
			if( find( k ) != NIL ) ans = "yes";
			cout << ans << endl;
		}
		else {
			int k;
			cin >> k;
			del( root, k, 1 );
		}
	}

}

