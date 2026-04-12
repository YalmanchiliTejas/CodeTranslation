#include <iostream>

class Dice {
private:
    int n, s, w, e, t, b;
public:
    Dice(int u, int v, int w, int x, int y, int z);
    ~Dice() {};

    void north();
    void south();
    void west();
    void east();
    void left();
    void right();
    int get_top() { return this->t; };
};

Dice::Dice(int u, int v, int w, int x, int y, int z) {
    this->t = u;
    this->s = v;
    this->e = w;
    this->w = x;
    this->n = y;
    this->b = z;
}

void Dice::north() {
    int tmp = this->n;
    this->n = this->t;
    this->t = this->s;
    this->s = this->b;
    this->b = tmp;
}

void Dice::south() {
    int tmp = this->s;
    this->s = this->t;
    this->t = this->n;
    this->n = this->b;
    this->b = tmp;
}

void Dice::west() {
    int tmp = this->w;
    this->w = this->t;
    this->t = this->e;
    this->e = this->b;
    this->b = tmp;
}

void Dice::east() {
    int tmp = this->e;
    this->e = this->t;
    this->t = this->w;
    this->w = this->b;
    this->b = tmp;
}

void Dice::left() {
    int tmp = this->e;
    this->e = this->s;
    this->s = this->w;
    this->w = this->n;
    this->n = tmp;
}

void Dice::right() {
    int tmp = this->e;
    this->e = this->n;
    this->n = this->w;
    this->w = this->s;
    this->s = tmp;
}

int main() {
    unsigned int n;
    std::string s;
    while (std::cin >> n, n != 0) {
        unsigned int res=0;
        Dice dice(1, 2, 3, 4, 5, 6);
        res += dice.get_top();
        for (int i=0; i<n; ++i) {
            std::cin >> s;
            if (s == "North") {
                dice.north();
            } else if (s == "East") {
                dice.east();
            } else if (s == "West") {
                dice.west();
            } else if (s == "South") {
                dice.south();
            } else if (s == "Left") {
                dice.left();
            } else if (s == "Right") {
                dice.right();
            }
            res += dice.get_top();
        }
        std::cout << res << std::endl;
    }
    return 0;
}

