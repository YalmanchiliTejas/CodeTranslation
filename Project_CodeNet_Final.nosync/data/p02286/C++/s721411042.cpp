//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Ken
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

class Node{
public:
	int id;
	Node* p_parent;
	Node* p_left_child;
	Node* p_right_child;
	int priority;

	Node(): id(-1), p_parent(NULL), p_left_child(NULL), p_right_child(NULL), priority(0){};
	Node(const int n):id(n), p_parent(NULL), p_left_child(NULL), p_right_child(NULL), priority(0){}
	Node(const int n, const int priority):id(n), p_parent(NULL), p_left_child(NULL), p_right_child(NULL), priority(priority){}
};

class BinarySearchTree{
public:
	map<int, Node> node_map;
	int root_id;

	BinarySearchTree(): node_map(), root_id(){};


	void insert(int input, int priority){
		node_map[input] = Node(input, priority); // THIS IS **PASS-BY-VALUE** !!!
		Node* y = NULL; //parent of x


		if(node_map.size()>=2){
		    Node* x = &node_map[root_id];
		    //cout << "x->id: " << x->id << "\n";

	    	while(x != NULL){
	    		y = x;

		    	if(node_map[input].id < x->id){
			    	x = x->p_left_child; // move to the left child
	    		}else{
		    		x = x->p_right_child; // move to the right child
		    	}
		    }
	    	//cout << "end of while loop\n";

	    	//if(x != NULL){
	    	//    cout << "x->id: " << x->id;}

	    	//if(y != NULL){
			//    cout << ", y->id: " << y->id;}

			//cout << ", z->id: " << node_map[z.id].id;

			//cout << "\n";

			node_map[input].p_parent = y;
		}

		if(y == NULL){ // T is empty
			root_id = node_map[input].id;
		}else if(input < y->id){
			y->p_left_child = &node_map[input];
		}else{
			y->p_right_child = &node_map[input];
		}
	}

	void printInorder(int node_id){
		Node& p_node = node_map[node_id];

		if(p_node.p_left_child != NULL){
			//cout << "print left branch\n";
		    printInorder(p_node.p_left_child->id);
		}

		cout << " " << node_id;

		if(p_node.p_right_child != NULL){
			//cout << "print right branch\n";
			printInorder(p_node.p_right_child->id);
		}
	}

	void printInorderTree(){
		printInorder(root_id);
	}

	void printPreorder(int node_id){
		Node& p_node = node_map[node_id];
		cout << " " << node_id;

		if(p_node.p_left_child != NULL){
		    printPreorder(p_node.p_left_child->id);
		}

		if(p_node.p_right_child != NULL){
			printPreorder(p_node.p_right_child->id);
		}
	}

	void printPreorderTree(){
		printPreorder(root_id);
	}

	void writeMap(){
		cout << "root id: " << root_id << ", root node: " << node_map[root_id].id << "\n";

		map<int, Node>::iterator p;
		for(p = node_map.begin(); p != node_map.end(); p++){
			cout << "No:" << p->first << ", id:" << p->second.id << ", priority:" << p->second.priority << "\n";
			Node& p_node = p->second;
			if(p_node.p_parent != NULL){
				cout << " parent: " << p_node.p_parent->id;
			}
			if(p_node.p_left_child != NULL){
				cout << " left_child: " << p_node.p_left_child->id;
			}
			if(p_node.p_right_child != NULL){
				cout << " right_child: " << p_node.p_right_child->id;
			}
			cout << "\n";
		}
	}

	bool find(int input){
		bool isFound = false;
		Node* x = &node_map[root_id];
		while(x != NULL){
			if(x->id == input){
				isFound = true;
				break;
			}else if(x->id > input){
				x = x->p_left_child;
			}else{
				x = x->p_right_child;
			}
		}

		return isFound;
	}

	void delete_node(int input){
		if(node_map.count(input)==0){
			return;
		}

		Node& z = node_map[input];
		if(z.p_left_child == NULL and z.p_right_child == NULL){
			if(z.id == root_id){// z is root
				root_id = -1;
			}

			if(z.p_parent->id < z.id){ // z is right child of z's parent
				z.p_parent->p_right_child = NULL;
			}else{ // z is left child of z's parent
				z.p_parent->p_left_child = NULL;
			}
			node_map.erase(input);
		}else if(z.p_left_child != NULL and z.p_right_child == NULL){
			if(z.id == root_id){
				z.p_left_child->p_parent = NULL;
				root_id = z.p_left_child->id;
				node_map.erase(input);
				return;
			}

			z.p_left_child->p_parent = z.p_parent;
			if(z.p_parent->id < z.id){ // z is right child of z's parent
				z.p_parent->p_right_child = z.p_left_child;
			}else{
				z.p_parent->p_left_child = z.p_left_child;
			}
			node_map.erase(input);
		}else if(z.p_left_child == NULL and z.p_right_child != NULL){
			if(z.id == root_id){
				z.p_right_child->p_parent = NULL;
				root_id = z.p_right_child->id;
				node_map.erase(input);
				return;
			}

			z.p_right_child->p_parent = z.p_parent;
			if(z.p_parent->id < z.id){ // z is right child of z's parent
				z.p_parent->p_right_child = z.p_right_child;
			}else{
				z.p_parent->p_left_child = z.p_right_child;
			}
			node_map.erase(input);
		}else{ // z has left and right child
			Node* x = z.p_right_child;
			Node* y = NULL; //x's parent
			while(x != NULL){
				y = x;
				x = x->p_left_child;
			}
			int old_z_id = z.id;

			if(z.id == root_id){
				root_id = y->id;
			}

			if(y->p_left_child == NULL and y->p_right_child == NULL){
				if(y->id == y->p_parent->p_left_child->id){
				    y->p_parent->p_left_child = NULL;
				}else if(y->id == y->p_parent->p_right_child->id){
					y->p_parent->p_right_child = NULL;
				}

			}else if(y->p_left_child == NULL and y->p_right_child != NULL){
				y->p_right_child->p_parent = y->p_parent;
				y->p_parent->p_left_child = y->p_right_child;
			}

			z.id = y->id;
			node_map[y->id] = z;

			node_map.erase(old_z_id);
		}
	}

	Node* rightRotate(int node_id){
		Node& t = node_map[node_id];
		Node* s = t.p_left_child;
		t.p_left_child = s->p_right_child;
		if(s->p_right_child != NULL){
		    s->p_right_child->p_parent = &t;
		}
		s->p_right_child = &t;

		if(t.id == root_id){
			root_id = s->id;
		}
		else if(t.p_parent->p_left_child == &t){
			t.p_parent->p_left_child = s;
		}else if(t.p_parent->p_right_child == &t){
			t.p_parent->p_right_child = s;
		}

		s->p_parent = t.p_parent;
		t.p_parent = s;
		return s;
	}

	Node* leftRotate(int node_id){
		Node& t = node_map[node_id];
		Node* s = t.p_right_child;
		t.p_right_child = s->p_left_child;
		if(s->p_left_child != NULL){
		    s->p_left_child->p_parent = &t;
		}
		s->p_left_child = &t;

		if(t.id == root_id){
			root_id = s->id;
		}
		else if(t.p_parent->p_left_child == &t){
			t.p_parent->p_left_child = s;
		}else if(t.p_parent->p_right_child == &t){
			t.p_parent->p_right_child = s;
		}

		s->p_parent = t.p_parent;
		t.p_parent = s;
		return s;
	}

	Node* insert(Node* p_node, int key, int priority){
		if(p_node == NULL){
			node_map[key] = Node(key, priority);
			if(node_map.size()==1){
				root_id = key;
			}

			return &node_map[key];
		}
		if(key == p_node->id){
			return p_node;
		}

		if(key < p_node->id){
			p_node->p_left_child = insert(p_node->p_left_child, key, priority);
			p_node->p_left_child->p_parent = p_node;
			if(p_node->priority < p_node->p_left_child->priority){
				p_node = rightRotate(p_node->id);
			}
		}else{ // key >= p_node->id
			p_node->p_right_child = insert(p_node->p_right_child, key, priority);
			p_node->p_right_child->p_parent = p_node;
			if(p_node->priority < p_node->p_right_child->priority){
				p_node = leftRotate(p_node->id);
			}
		}

		return p_node;
	}

	Node* delete_node(Node* p_node, int key){
		if(p_node == NULL){
			//cout << "delete_node(p_node: NULL, key:" << key << "\n";
			return NULL;
		}

		//cout << "detele_node(p_node:" << p_node->id << ", key:" << key << ")\n";

		if(key < p_node->id){
			p_node->p_left_child = delete_node(p_node->p_left_child, key);
		}else if(key > p_node->id){
			p_node->p_right_child = delete_node(p_node->p_right_child, key);
		}else{
			return _delete(p_node, key);
		}

		return p_node;
	}

	Node* _delete(Node* p_node, int key){
		//cout << "_delete(p_node:" << p_node->id << ", key:" << key << ")\n";

		if(p_node->p_left_child == NULL and p_node->p_right_child == NULL){
			return NULL;
		}else if(p_node->p_left_child == NULL){
			p_node = leftRotate(p_node->id);
		}else if(p_node->p_right_child == NULL){
			p_node = rightRotate(p_node->id);
		}else{
			if(p_node->p_left_child->priority > p_node->p_right_child->priority){
				//cout << "_delete(p_node:" << p_node->id << ", key:" << key << "), " << "rigthRotate(" << p_node->id << ")\n";
				p_node = rightRotate(p_node->id);
				//cout << "rightRoate done\n";
			}else{
				//cout << "_delete(p_node:" << p_node->id << ", key:" << key << "), " << "leftRotate(" << p_node->id << ")\n";
				p_node = leftRotate(p_node->id);
			}
		}

		return delete_node(p_node, key);
	}
};


int main() {
	BinarySearchTree tree;

	int n, input, priority;
	string command;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> command;
		if(command == "insert"){
			cin >> input >> priority;
			//cout << "insert(" << input << ")\n";
			//tree.insert(input, priority);
			if(tree.node_map.size()==0){
				tree.insert(NULL, input, priority);
			}else{
				tree.insert(&tree.node_map[tree.root_id], input, priority);
			}
			//tree.writeMap();
			//cout << "\n\n\n";
		}
		if(command == "print"){
			//cout << "printInorderTree()\n";
			tree.printInorderTree();
			cout << "\n";
			//cout << "printPreorderTree()\n";
			tree.printPreorderTree();
			cout << "\n";
		}
		if(command == "find"){
			cin >> input;
			bool isFound = tree.find(input);
			if(isFound){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}
		if(command == "delete"){
			cin >> input;
			tree.delete_node(&tree.node_map[tree.root_id], input);
			//cout << "delete: " << input << "\n";
			//tree.writeMap();
			//cout << "\n\n\n";
		}
		if(command == "right_rotate"){
			cin >> input;
			tree.rightRotate(input);
			//cout << "right_rotate: " << input << "\n";
			//tree.writeMap();
			//cout << "\n\n\n";
		}
		if(command == "left_rotate"){
			cin >> input;
			tree.leftRotate(input);
			//cout << "left_rotate: " << input << "\n";
			//tree.writeMap();
			//cout << "\n\n\n";
		}
	}

	return 0;
}

