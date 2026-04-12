#include <iostream>

using namespace std;

class Node {
public:
    int key;
    int pri;
    Node* left;
    Node* right;
    
    Node() : key(-1), pri(-1), left(NULL), right(NULL) {}
    Node( int k, int p ) : key(k), pri(p), left(NULL), right(NULL) {}    

    friend std::ostream& operator << ( std::ostream& os, Node& node ) {
	os << " " << node.key;
	return os;
    }
};

Node* RightRotate( Node* t ) {
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

Node* LeftRotate( Node* t ) {
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* Insert( Node* t, int key, int pri ) {

    if ( t == NULL ) return new Node( key, pri );

    if ( key == t->key ) return t;

    if ( key < t->key ) {

	t->left = Insert( t->left, key, pri );
	
	if ( t->pri < t->left->pri ) t = RightRotate( t );
    }
    else {

	t->right = Insert( t->right, key, pri );

	if ( t->pri < t->right->pri ) t = LeftRotate( t );
    }
    
    return t;
}

Node* Erase( Node* t, int key ) {

    if ( t == NULL ) return NULL;

    if ( key == t->key ) {
	
	if      ( t->left == NULL && t->right == NULL ) return NULL;
	else if ( t->left == NULL ) t = LeftRotate( t );
	else if ( t->right == NULL ) t = RightRotate( t );
	else {
	    if ( t->left->pri > t->right->pri ) t = RightRotate( t );
	    else t = LeftRotate( t );
	}
	
	return Erase( t, key );
    }

    if ( key < t->key ) t->left = Erase( t->left, key );
    else t->right = Erase( t->right, key );

    return t;
}

bool Find( Node* t, int key ) {

    if ( t == NULL ) return false;

    if ( key == t->key ) return true;

    if ( key < t->key ) return Find( t->left, key );
    return Find( t->right, key );

}

void PrintInOrder( Node* t ) {
    if ( !t ) return;
    if ( t->left ) PrintInOrder( t->left );
    cout << *t;
    if ( t->right ) PrintInOrder( t->right );
}

void PrintPreOrder( Node* t ) {
    if ( !t ) return;
    cout << *t;
    if ( t->left ) PrintPreOrder( t->left );
    if ( t->right ) PrintPreOrder( t->right );
}

int main() {

    Node* root = NULL;

    int n;
    cin >> n;

    int k, p;
    string s;
    for ( int i=0; i<n; ++i ) {

	cin >> s;

	if ( s == "insert" ) {
	    cin >> k >> p;
	    root = Insert( root, k, p );
	}
	else if ( s == "find" ) {
	    cin >> k;
	    if ( Find( root, k ) ) cout << "yes\n";
	    else cout << "no\n";
	}
	else if ( s == "delete" ) {
	    cin >> k;
	    root = Erase( root, k );
	}
	else if ( s == "print" ) {
	    PrintInOrder( root );
	    cout << endl;
	    PrintPreOrder( root );
	    cout << endl;
	}
	
    }
    
    return 0;
}

