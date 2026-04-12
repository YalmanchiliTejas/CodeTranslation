#include <iostream>
using namespace std;

#define SAFE_DELETE( x ) { if ( x ){ delete x; x = NULL; } }

struct tCell{
	tCell() : num( 0 ), result( 0 ), prev( NULL ), next( NULL ){}

	int num, result;
	tCell *prev, *next;
};

class MyArray{
public:
	MyArray() : mSize( 0 ), head( NULL ), tail( NULL ), rankList( NULL ){
		head = new tCell;
		tail = new tCell;
		head->next = tail;
		tail->prev =head;
	}
	~MyArray(){
		init();
		SAFE_DELETE( rankList );
		SAFE_DELETE( tail );
		SAFE_DELETE( head );
	}

	void init(){
		for ( int i = mSize; i > 0; --i ){
			tCell* cell = tail->prev;
			cell->prev->next = cell->next;
			cell->next->prev = cell->prev;
			SAFE_DELETE( cell );
		}
		mSize = 0;
		if ( rankList ){
			SAFE_DELETE( rankList );
			rankList = new MyArray;
		}
	}
	void pushBack( int n, int r ){
		++mSize;
		tCell* cell = new tCell;
		cell->num = n;
		cell->result = r;
		cell->prev = tail->prev;
		cell->next =tail;
		cell->prev->next = cell;
		cell->next->prev = cell;
	}
	void createRank(){
		rankList = new MyArray;
		rankList->init();
		tCell* cell = head;
		for ( int i = 0; i < mSize; ++i ){
			cell = cell->next;
			if ( !rankList->find( cell->result ) ){
				rankList->pushBack( 0, cell->result );
			}
		}
		rankList->sort();
	}
	bool find( int index ){
		tCell* cell = head;
		for ( int i = 0; i < mSize; ++i ){
			cell = cell->next;
			if ( index == cell->result ) return true;
		}
		return false;
	}
	void sort(){
		for ( int i = 0; i < mSize-1; ++i ){
			tCell* cell = head;
			for ( int j = 0; j < mSize-1-i; ++j ){
				cell = cell->next;
				if ( cell->result < cell->next->result ){
					int t = cell->result;
					cell->result = cell->next->result;
					cell->next->result = t;
				}
			}
		}
	}
	int size(){ return mSize; }
	int getRank( int index ){
		tCell* cell = head;
		for ( int i = 0; i < mSize; ++i ){
			cell = cell->next;
			if ( index == cell->num ) break;
		}
		for ( int i =0; i < rankList->size(); ++i ){
			if ( cell->result == (*rankList)[ i ].result ) return i+1;
		}
		return 0;
	}

	tCell operator[]( int index ){
		tCell* cell = head->next;
		for ( int i = 0; i < index; ++i ){
			cell = cell->next;
		}
		return *cell;
	}

private:

	int mSize;
	tCell *head, *tail;
	MyArray* rankList;
};

int main(){
	int num, result;
	char c;
	MyArray list;

	while ( cin >> num >> c >> result ){
		if ( !num && !result ) break;
		list.pushBack( num, result );
	}
	list.createRank();

	while ( cin >> num ){
		cout << list.getRank( num ) << endl;
	}

	return 0;
}