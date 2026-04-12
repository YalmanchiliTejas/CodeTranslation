// #include<initializer_list>
// #include<iostream>

template<typename type>
class BTree {
public :
	static const int default_min_degree = 2;
	bool MULTISET = true; // true -> duplicate 　false -> not duplicate 
	int SEARCH = 1; // linear search ->0  binary search ->1
	bool COUNT_NUM = true;
	
	int number_of_element;
	int min_degree;
	
	
	class Node {
	public :
		bool leaf;
		int number_of_key;
		int count;
		
		Node* parent;
		int *sum;
		type *key;
		Node** children;
		BTree<type>* btree;
		
		Node(BTree<type>* btree, Node* parent = nullptr): btree(btree), parent(parent) {init();}	
		
		~Node(){
			delete[] sum;
			delete[] key;
			delete[] children;
		}
		
		void init() {
			leaf = true;
			number_of_key = 0;
			count = 1;
			
			key = new type[btree->min_degree * 2 - 1];
			children = new Node*[btree->min_degree * 2];
			
			if(btree->COUNT_NUM) {
				sum = new int[btree->min_degree * 2];
				sum[0] = 0;
			}
			
		}
	};
	
	Node* root;
	
	
	class jnode {
	public:
		Node* node;
		int index;
		
		jnode(Node* node = nullptr, int index = 0): node(node), index(index) {}	
		
		jnode& operator ++(){
			
			if(node == nullptr) {
				if(root != nullptr){
					node = root;
					while(!node->leaf){
						node = node->children[0];
					}
				}
				index = 0;
			} else if(node->leaf) {
				if(node->number_of_key <= index - 1) {
					node = nullptr;
				} else {
					index++;
				}
			} else {
				node = node->children[index+1];
				
				while(!node->leaf){
					node = node->children[0];
				}
				
				index = 0;
			}
			
			return *this;
		}
		
		jnode operator ++(int) {
			jnode j = *this;
			
			++(*this);
			
			return j;
		}
		
		jnode& operator --(){
			
			if(node == nullptr) {
				if(root != nullptr){
					node = root;
					while(!node->leaf){
						node = node->children[node->children->number_of_key];
					}
				}
				index = node->number_of_key-1;
			} else if(node->leaf) {
				if(index == 0) {
					node = nullptr;
				} else {
					index--;
				}
			} else {
				node = node->children[index];
				
				while(!node->leaf){
					node = node->children[node->children->number_of_key];
				}
				
				index = node->number_of_key - 1;
			}
		}
		
		jnode operator --(int) {
			jnode j = *this;
			
			--(*this);
			
			return j;
		}		
		
		bool operator == (const jnode &j) const {
			return node ==  j.node && index == j.index;
		}
	};
	
	
	BTree(int min_degree = default_min_degree) : min_degree(min_degree){ create();};
	
	~BTree(){
		all_delete(root);
	}
	
	int index_search(Node *node, int key, int k){  // lower bound
		int index;
		
		if(k == 0){
			// linear search
			
			for(index = 0; index < node->number_of_key && (node->key[index] < key); index++);
		} else if(k == 1){
			//binary search
			
			index = node->number_of_key;
			int low = -1, med;
			while(low + 1< index){
				int med = (low + index) >> 1;
				
				if((node->key[med] < key)) {
					low = med;
				} else {
					index = med;
				}
			}
		}
		
		return index;
	}
	
	int index_search2(Node *node, int key, int k){ // upper bound
		int index;
		
		if(k == 0){
			// linear search
			
			for(index = 0; index < node->number_of_key && (key >= node->key[index]); index++);
		} else if(k == 1){
			//binary search
			
			index = node->number_of_key;
			int low = -1, med;
			while(low + 1 < index){
				int med = (low + index) >> 1;
				
				if(key >= node->key[med]) {
					low = med;
				} else {
					index = med;
				}
			}
		}
		
		return index;
	}
	
	int sum_search(Node *node, int num, int k){
		int index = 0;
		
		if(k == 0){
			// linear search
			
			for(index = 0; index < node->number_of_key && node->sum[index] < num; index++);
		} else if(k == 1){
			//binary search
			
			index = node->number_of_key;
			int low = -1, med;
			while(low + 1 < index){
				int med = (low + index) >> 1;
				
				if(node->sum[med] < num) {
					low = med;
				} else {
					index = med;
				}
			}
		}
		
		return index;
	}
	
	void all_delete(Node* node){
		
		if(!node->leaf) {
			for(int i = 0; i <= node->number_of_key; i++){
				all_delete(node->children[i]);
			}
		}
		
		delete node;
	}
	
	void create(){
		number_of_element = 0;
		
		root = new Node(this);
	}
	
	int lower_bound(type key){
		return lower_bound(root, key);
	}
	
	int lower_bound(Node *node, type key){
		int index = index_search(node, key, SEARCH);
		
		if(node->leaf) {
			if(index < node->number_of_key) return node->sum[index];
			else return node->number_of_key;
		} else {
			 if(index) return lower_bound(node->children[index], key) + node->sum[index-1] + 1;
			else return lower_bound(node->children[index], key);
		}
	}
	
	int upper_bound(type key){
		return upper_bound(root, key);
	}
	
	int upper_bound(Node *node, type key){
		int index = index_search2(node, key, SEARCH);
		
		if(node->leaf) {
			if(index < node->number_of_key) return node->sum[index];
			else return node->number_of_key;
		} else {
			 if(index) return upper_bound(node->children[index], key) + node->sum[index-1] + 1;
			else return upper_bound(node->children[index], key);
		}
	}
	
	int size(){
		return number_of_element;
	}
	
	Node* search(type k){
		return search(root, k);
	}
	
	Node* search(Node* node, type key){
		
		int index = index_search(node, key, SEARCH);
		
		
		if(index < node->number_of_key && (node->key[index] == key)) {
			return node;
		} else if(node->leaf) {
			return nullptr;
		} else {
			return search(node->children[index], key);
		}
	}
	
	void operation(Node *node){
		if(COUNT_NUM) count_number(node);
	}
	
	void count_number(Node *node){
		
		if(node == nullptr) return;
		
		if(node->leaf) {
			for(int i = 0; i <= node->number_of_key; i++) {
				node->sum[i] = 0;
				if(i) {
					node->sum[i] += node->sum[i-1] + node->count;
				}
			}
		} else {
			for(int i = 0; i <= node->number_of_key; i++){
				
				node->sum[i] = node->children[i]->sum[node->children[i]->number_of_key];
			
				if(i) {
					node->sum[i] += node->sum[i-1] + 1;
				}
			}
		}
	}
	
	
	type nth_element(int num){
		if(num < 0 || num >= size()) return type();
		return nth_element(root, num);
	}
	
	type nth_element(Node* node, int num){
		int index = sum_search(node, num, SEARCH);
		
		if(index < node->number_of_key && num == node->sum[index]) {
			return node->key[index];
		} else {
			if(node->leaf) {
				// どうしてここに？
			} else {
				if(index) return nth_element(node->children[index], num - node->sum[index-1] - 1);
				else return nth_element(node->children[index], num);
			}
		}
	}
	
	/*
	std::pair<Node*, type> nth_element(int num){
		if(num < 0 || num >= size()) return std::make_pair(nullptr, type());
		return nth_element(root, num);
	}
	
	std::pair<Node*, type> nth_element(Node* node, int num){
		int index = sum_search(node, num, SEARCH);
		
		if(index < node->number_of_key && num == node->sum[index]) {
			return std::make_pair(node, node->key[index]);
		} else {
			if(node->leaf) {
				// どうしてここに？
			} else {
				if(index) return nth_element(node->children[index], num - node->sum[index-1] - 1);
				else return nth_element(node->children[index], num);
			}
		}
	}
	*/
	
	void split_child(Node* node, int index){
		Node *right_child = new Node(this, node);
		Node *left_child = node->children[index];
		
		right_child->leaf =  left_child->leaf;
		right_child->number_of_key = min_degree - 1;
		
		for(int j = 0; j < min_degree - 1; j++){
			right_child->key[j] = left_child->key[j + min_degree];
		}
		
		if(!left_child->leaf) {
			
			for(int j = 0; j < min_degree; j++){
				right_child->children[j] = left_child->children[j + min_degree];
			}
			
		}
		
		left_child->number_of_key = min_degree - 1;
		
		for(int j = node->number_of_key; j > index; j--){
			node->children[j+1] = node->children[j];
		}
		
		node->children[index+1] = right_child;
		
		for(int j = node->number_of_key - 1; j >= index; j--){
			node->key[j+1] = node->key[j];
		}
		
		node->key[index] = left_child->key[min_degree-1];
		
		node->number_of_key++;
		
		right_child->parent = node;
		
		operation(right_child);
		operation(left_child);
	}
	
	void insert_nonfull(Node* node, type key){
		int index = node->number_of_key - 1;
		
		if(node->leaf) {
			
			for(; index >= 0 && (key < node->key[index]); index--){
				node->key[index+1] = node->key[index];
			}
			
			node->key[index+1] = key;
			node->number_of_key++;
		} else {
			for(; index >= 0 && (key < node->key[index]); index--);
			
			index++;
			
			if(node->children[index]->number_of_key == 2 * min_degree - 1) {
				split_child(node, index);
				
				if((node->key[index] < key)) index++;
			}
			
			insert_nonfull(node->children[index], key);
		}
		
		operation(node);
	}
	
	void insert(type key){
		if(!MULTISET && search(key) != nullptr) return ;
		
		number_of_element++;
		
		_insert(key);
	}
	
	void _insert(type key){
		Node* temp_root = root;
		
		if(root->number_of_key == 2 * min_degree - 1) {
			Node* new_node = new Node(this);
			
			root = new_node;
			
			root->leaf = false;
			root->children[0] = temp_root;
			root->parent = new_node;
			

			split_child(root, 0);
			insert_nonfull(root, key);
		} else {
			insert_nonfull(root, key);
		}
	}
	
	void erase(type key){
		erase(root, key);
		
		while(root->number_of_key == 0 && !root->leaf) {
			Node *temp = root;
			
			root = root->children[0];
			root->parent = nullptr;		
			
			delete temp;
		}
	}
	
	void erase(Node* node, type key){
		int index = index_search(node, key, SEARCH);
		
		if(index < node->number_of_key && (node->key[index] == key)) {
			if(node->leaf) {
				for(int i = index; i + 1 < node->number_of_key; i++){
					node->key[i] = node->key[i + 1];
				}
				
				number_of_element--;
				node->number_of_key--;
				
			} else {
				Node* child1 = node->children[index];
				Node* child2 = node->children[index+1];
				
				if(child1->number_of_key >= min_degree) {
					Node *maximum = child1;
					
					while(!maximum->leaf){
						maximum = maximum->children[maximum->number_of_key];
					}
					
					node->key[index] = maximum->key[maximum->number_of_key-1];
					
					erase(child1, node->key[index]);
				} else if(child2->number_of_key >= min_degree){
					Node *minimum = child2;
					
					while(!minimum->leaf){
						minimum = minimum->children[0];
					}
				
					node->key[index] = minimum->key[0];
					
					erase(child2, node->key[index]);
				} else {
					
					child1->key[min_degree - 1] = key;
					
					for(int i = min_degree; i < min_degree * 2 - 1; i++){
						child1->key[i] = child2->key[i - min_degree];
					}
					
					for(int i = min_degree; i < min_degree * 2; i++){
						child1->children[i] = child2->children[i - min_degree];
					}
					
					delete child2;
					
					child1->number_of_key = min_degree * 2 - 1;
					
					for(int i = index; i + 1 < node->number_of_key; i++){
						node->key[i] = node->key[i + 1];
					}
					for(int i = index + 1; i < node->number_of_key; i++){
						node->children[i] = node->children[i + 1];
					}
					
					node->number_of_key--;
					
					erase(child1, key);
				}
			}
		} else if(node->leaf) {
		
		} else {
		
			Node* child0 = nullptr;
			Node* child1 = child1 = node->children[index];;
			Node* child2 = nullptr;
			
			if(index >= 1) child0 = node->children[index-1];
			if(index + 1 <= node->number_of_key) child2 = node->children[index+1];
			
			if(child1 == nullptr) { 
				//　ﾊﾞｶｼﾞｬﾈｰﾉ
				return ;
			} else if(child1->number_of_key >= min_degree) {
				erase(child1, key);
			} else if(child0 != nullptr && child0->number_of_key >= min_degree){
				index--;
				
				for(int i = child1->number_of_key - 1; i >= 0; i--){
					child1->key[i+1] = child1->key[i];
				}
				for(int i = child1->number_of_key; i >= 0; i--){
					child1->children[i+1] = child1->children[i];
				}
				
				child1->key[0] = node->key[index];
				child1->children[0] = child0->children[child0->number_of_key];
				
				node->key[index] = child0->key[child0->number_of_key-1];
				
				child0->number_of_key--;
				child1->number_of_key++;
				
				erase(child1, key);
				
			} else if(child2 != nullptr && child2->number_of_key >= min_degree){
				
				child1->key[child1->number_of_key] = node->key[index];
				child1->children[child1->number_of_key + 1] = child2->children[0];
				
				node->key[index] = child2->key[0];
				
				for(int i = 0; i + 1 < child2->number_of_key; i++){
					child2->key[i] = child2->key[i+1];
				}
				for(int i = 0; i < child2->number_of_key; i++){
					child2->children[i] = child2->children[i+1];
				}
				
				child2->number_of_key--;
				child1->number_of_key++;
				
				operation(child2);
				erase(child1, key);
			} else if(child2 != nullptr || child0 != nullptr){
				Node* child_left, *child_right;
				
				if(child2 != nullptr){
					child_left = child1;
					child_right = child2;
					
				} else if(child0 != nullptr){
					child_left = child0;
					child_right = child1;
					
					index--;
				}
				
				child_left->key[min_degree - 1] = node->key[index];
					
				for(int i = min_degree; i < min_degree * 2 - 1; i++){
					child_left->key[i] = child_right->key[i - min_degree];
				}
				
				for(int i = min_degree; i < min_degree * 2; i++){
					child_left->children[i] = child_right->children[i - min_degree];
				}
				
				delete child_right;
				
				child_left->number_of_key = min_degree * 2 - 1;
				
				for(int i = index; i + 1 < node->number_of_key; i++){
					node->key[i] = node->key[i + 1];
				}
				
				for(int i = index + 1; i < node->number_of_key; i++){
					node->children[i] = node->children[i + 1];
				}
				
				node->number_of_key--;
				
				operation(node);
				erase(child_left, key);
			} else {
				
			}
		}
		
		
		operation(node);
	}
	
	const type operator[](int num) & {
		return nth_element(num);
	}
};




#include<iostream>
signed main(){
	
	using namespace std;
	BTree<int> bt;
	int n, q;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		
		bt.insert(a);
	}
	// return 0;
	cin>>q;
	
	for(int i = 0; i < q; i++){
		int k;
		
		cin>>k;
		
		cout<<bt.lower_bound(k)<<endl;
		//cout<<bt.upper_bound(k-1)<<endl;
	}
	return 0;
}
