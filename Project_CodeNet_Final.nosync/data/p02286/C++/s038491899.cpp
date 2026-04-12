#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stdexcept>


using std::string;
using std::vector;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// util
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> split(const std::string& input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// user func
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printList(const vector<int>& list) {
    // print
    for(int i = 0; i < list.size(); i++){
        printf(" %d", list[i]);
    }
    printf("\n");
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// logic
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Node;

class Node{
public:
    Node(int value, int priority)
        :value(value)
        ,priority(priority)
    {
    }
    void Value(int value) {
        this->value = value;
    }
    int Value(){
        return this->value;
    }
    int Priority(){
        return this->priority;
    }
    void Priority(int priority){
        this->priority = priority;
    }
    std::shared_ptr<Node> Left(){
        return this->left;
    }
    void Left(std::shared_ptr<Node> left){
        this->left = left;
        if (left) this->left->Parent(this);
    }
    std::shared_ptr<Node> Right(){
        return this->right;
    }
    void Right(std::shared_ptr<Node> right){
        this->right = right;
        if (right) this->right->Parent(this);
    }
    bool HasLeft(){
        return this->left ? true : false;
    }
    bool HasRight(){
        return this->right ? true : false;
    }
    Node* Parent(){
        return this->parent;
    }
    void Parent(Node* parent){
        this->parent = parent;
    }
    int CountChild(){
        int count = 0;
        if (this->HasLeft()) count++;
        if (this->HasRight()) count++;
        return count;
    }

    std::shared_ptr<Node> FirstChild() {
        if(this->HasLeft()) return this->Left();
        if(this->HasRight()) return this->Right();
        return nullptr;
    }

    bool IsEqualLeft(int val){
        if (!this->HasLeft()) return false;
        return this->Left()->Value() == val;
    }

private:
    int value;
    int priority;
    std::shared_ptr<Node> left = nullptr ;
    std::shared_ptr<Node> right = nullptr;
    Node* parent = nullptr;
};

using NodePtr = std::shared_ptr<Node>;

class BinarySearchTree{
public:
    void Insert(int value, int priority){
        if(!this->root){
            root = std::make_shared<Node>(value, priority);
            return;
        }
        InsertProc(this->root, value, priority);
    }
    
    bool Find(int value){
        if(!this->root) return false;
        return this->FindProc(this->root, value);
    }
    void Delete(int value){
        this->FindAndDelete(this->root, value);
    }
    vector<int> Preorder(){
        vector<int> result;
        this->PreorderProc(this->root, result);
        return result;
    }
    vector<int> Inorder(){
        vector<int> result;
        this->InorderProc(this->root, result);
        return result;
    }

private:
    NodePtr root = nullptr;

    NodePtr InsertProc(NodePtr node, int value, int priority){
        if (!node) return std::make_shared<Node>(value, priority);
        if (value == node->Value()) return node;
        
        if (value < node->Value()){
            NodePtr t = InsertProc(node->Left(), value, priority);
            node->Left(t);
            if (node->Priority() < node->Left()->Priority()){
                node = RightLotate(node);
            }
        } else {
            NodePtr t = InsertProc(node->Right(), value, priority);
            node->Right(t);
            if (node->Priority() < node->Right()->Priority()){
                node = LeftLotate(node);
            }
        }
        return node;
    }

    NodePtr RightLotate(NodePtr node){
        // printf("RL\n");
        auto s = node->Left();
        node->Left(s->Right());
        // if (s) {
            s->Parent(node->Parent());
            s->Right(node);
        // }
        if (!s->Parent()) this->root = s;
        return s;
    }

    NodePtr LeftLotate(NodePtr node){
        // printf("LL\n");
        auto s = node->Right();
        node->Right(s->Left());
        // if (s) {
            s->Parent(node->Parent());
            s->Left(node);
        // }
        if (!s->Parent()) this->root = s;
        return s;
    }


    void PreorderProc(NodePtr current, vector<int>& list){
        list.push_back(current->Value());
        if (current->HasLeft()) PreorderProc(current->Left(), list);
        if (current->HasRight()) PreorderProc(current->Right(), list);
    }
    
    void InorderProc(NodePtr current, vector<int>& list){
        if (current->HasLeft()){
            InorderProc(current->Left(), list);
        }
        list.push_back(current->Value());
        if (current->HasRight()) {
            InorderProc(current->Right(), list);
        }
    }

    bool FindProc(NodePtr current, int value){
        if (current->Value() == value){
            return true;
        } else if (value < current->Value()) {
            if(!current->HasLeft()) return false;
            return this->FindProc(current->Left(), value);
        } else {
        // if (current->Value() < value) {
            if(!current->HasRight()) return false;
            return this->FindProc(current->Right(), value);
        }
    }

    NodePtr FindNode(NodePtr current, int value){
        if (current->Value() == value){
            return current;
        } else if (value < current->Value()) {
            if(!current->HasLeft()) return nullptr;
            return this->FindNode(current->Left(), value);
        } else {
        // if (current->Value() < value) {
            if(!current->HasRight()) return nullptr;
            return this->FindNode(current->Right(), value);
        }
    }

    // inorder s next
    NodePtr FindNext(NodePtr node){
        if (node->HasLeft()) return FindNext(node->Left());
        return node;
    }

    void dump(NodePtr node){
        printf("%d %d(%d, %d)\n", 
            node->Value(),
            node->Parent() ? node->Parent()->Value() : - 1, 
            node->Left() ? node->Left()->Value() : -1,
            node->Right() ? node->Right()->Value() : -1);
        if (node->HasLeft()) dump(node->Left());
        if (node->HasRight()) dump(node->Right());
    }

    NodePtr FindAndDelete(NodePtr node, int value) {
        if (!node) return nullptr;
        if (value < node->Value()) {
            node->Left(FindAndDelete(node->Left(), value));
        } else if( node->Value() < value ) {
            node->Right(FindAndDelete(node->Right(), value));
        } else {
            return DeleteProc(node, value);
        }
        return node;
    }

    NodePtr DeleteProc(NodePtr current, int value){
        // dump(current);
        // remove current
        if (current->CountChild() == 0) {
            if (current->Parent()->IsEqualLeft(current->Value())){
                current->Parent()->Left(nullptr);
            }else{
                current->Parent()->Right(nullptr);
            }
            return nullptr;
        } else if (current->CountChild() == 1) {
            if (current->Right()) {
                current = LeftLotate(current);
            } else {
                current = RightLotate(current);
            }
        } else {
            if (current->Right()->Priority() <= current->Left()->Priority()) {
                current = RightLotate(current);
            } else {
                current = LeftLotate(current);
            }
        }
        return FindAndDelete(current, value);
    }
};

void solve() {
    // Treap
    int n;
    scanf("%d", &n);
    BinarySearchTree tree;
    for(int i = 0; i < n; i++){
        char buffer[127];
        scanf("%s", buffer);
        string command(buffer);
        if(command == "insert"){
            int v;
            int priority;
            scanf(" %d %d", &v, &priority);
            tree.Insert(v, priority);
        } else if(command == "find" ){
            int v;
            scanf(" %d", &v);
            printf("%s\n", tree.Find(v) ? "yes" : "no");
        } else if(command == "delete") {
            int v;
            scanf(" %d", &v);
            tree.Delete(v);
        
        } else if(command == "print"){
            auto in = tree.Inorder();
            printList(in);
            auto pre = tree.Preorder();
            printList(pre);
        }

    }
        
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    solve();
    return 0;
}
