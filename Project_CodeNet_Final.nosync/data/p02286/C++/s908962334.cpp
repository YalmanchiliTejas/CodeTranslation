#include <iostream>
#include <string>
#include <memory>
#include <chrono>

template <class Key>
struct Treap {
    using Prior = uint64_t;

    struct Node {
        Key key;
        Prior prior;
        std::unique_ptr<Node> lch, rch;

        explicit Node(Key key = 0, Prior prior = 0)
            : key(key), prior(prior), lch(nullptr), rch(nullptr) {}
    };
    using Tree = std::unique_ptr<Node>;

    Tree root;

    explicit Treap() : root(nullptr) {}

    void split(Tree& t, Key key, Tree& lt, Tree& rt) {
        if (!t) {
            lt = nullptr;
            rt = nullptr;
        } else if (key < t->key) {
            Tree tmp_rt = nullptr;
            split(t->lch, key, lt, tmp_rt);
            t->lch = std::move(tmp_rt);
            rt = std::move(t);
        } else {
            Tree tmp_lt = nullptr;
            split(t->rch, key, tmp_lt, rt);
            t->rch = std::move(tmp_lt);
            lt = std::move(t);
        }
    }

    void merge(Tree& lt, Tree& rt, Tree& t) {
        if (!lt || !rt) {
            t = std::move(lt ? lt : rt);
        } else if (lt->prior > rt->prior) {
            merge(lt->rch, rt, lt->rch);
            t = std::move(lt);
        } else {
            merge(lt, rt->lch, rt->lch);
            t = std::move(rt);
        }
    }

    void insert(Key key, Prior prior) {
        Tree lt, rt;
        split(root, key, lt, rt);
        root = std::make_unique<Node>(key, prior);
        merge(lt, root, root);
        merge(root, rt, root);
    }

    void erase(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);

        Tree tmp_rt;
        split(rt, key, root, tmp_rt);
        rt = std::move(tmp_rt);

        merge(lt, rt, root);
    }

    bool find(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);

        Tree tmp_rt;
        split(rt, key, root, tmp_rt);
        rt = std::move(tmp_rt);

        bool result = (root != nullptr);
        merge(lt, root, root);
        merge(root, rt, root);
        return result;
    }

    void dump_inner(Tree& t) {
        if (!t) return;

        std::cerr << "(" << t->prior << "," << t->key << ")" << std::endl;
        dump_inner(t->lch);
        std::cerr << "(" << t->prior << "," << t->key << ")" << std::endl;

        dump_inner(t->rch);
        std::cerr << "(" << t->prior << "," << t->key << ")" << std::endl;
    }

    void dump() {
        std::cerr << "----- begin -----" << std::endl;
        dump_inner(root);
        std::cerr << "------ end ------" << std::endl;
    }

    void print_inner(Tree& t) {
        if (!t) return;

        print_inner(t->lch);
        std::cout << " " << t->key;
        print_inner(t->rch);
    }

    void print_first(Tree& t) {
        if (!t) return;

        std::cout << " " << t->key;
        print_first(t->lch);
        print_first(t->rch);
    }

    void print() {
        print_inner(root);
        std::cout << std::endl;
        print_first(root);
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    Treap<int> treap;
    while (n--) {
        std::string t;
        std::cin >> t;

        if (t == "print") {
            treap.print();
        } else if (t == "insert") {
            int key, pri;
            std::cin >> key >> pri;
            treap.insert(key, pri);
        } else if (t == "find") {
            int key;
            std::cin >> key;
            std::cout << (treap.find(key) ? "yes" : "no") << std::endl;
        } else if (t == "delete") {
            int key;
            std::cin >> key;
            treap.erase(key);
        }
    }
    return 0;
}

