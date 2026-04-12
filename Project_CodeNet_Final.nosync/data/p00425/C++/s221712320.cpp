#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

enum Face{
    TOP,
    SOUTH,
    EAST,
    WEST,
    NORTH,
    BOTTOM,
};
 
class Dice{
private:
    std::vector<int> faces_;  
 
public:
    Dice(const std::vector<int> &labels);
 
    ~Dice();
 
    void roll_north();
 
    void roll_east();
 
    void roll_west();
 
    void roll_south();
 
    void roll_left();
 
    void roll_right();
 
    void roll_to(char d);
 
    int get_cur_label(char f);
 
    bool operator ==(Dice &r);
};
 
Dice::Dice(const std::vector<int> &labels) : faces_(labels){
    return;
}
 
Dice::~Dice(){
    return;
}
 
void Dice::roll_north(){
    int tmp = faces_[TOP];
    faces_[TOP] = faces_[SOUTH];
    faces_[SOUTH] = faces_[BOTTOM];
    faces_[BOTTOM] = faces_[NORTH];
    faces_[NORTH] = tmp;
    return;
}
 
void Dice::roll_east(){
    int tmp = faces_[TOP];
    faces_[TOP] = faces_[WEST];
    faces_[WEST] = faces_[BOTTOM];
    faces_[BOTTOM] = faces_[EAST];
    faces_[EAST] = tmp;
    return;
}
 
void Dice::roll_west(){
    int tmp = faces_[TOP];
    faces_[TOP] = faces_[EAST];
    faces_[EAST] = faces_[BOTTOM];
    faces_[BOTTOM] = faces_[WEST];
    faces_[WEST] = tmp;
    return;
}
 
void Dice::roll_south(){
    int tmp = faces_[TOP];
    faces_[TOP] = faces_[NORTH];
    faces_[NORTH] = faces_[BOTTOM];
    faces_[BOTTOM] = faces_[SOUTH];
    faces_[SOUTH] = tmp;
    return;
}
 
void Dice::roll_left(){
    int tmp = faces_[SOUTH];
    faces_[SOUTH] = faces_[WEST];
    faces_[WEST] = faces_[NORTH];
    faces_[NORTH] = faces_[EAST];
    faces_[EAST] = tmp;
    return;
}
 
void Dice::roll_right(){
    int tmp = faces_[SOUTH];
    faces_[SOUTH] = faces_[EAST];
    faces_[EAST] = faces_[NORTH];
    faces_[NORTH] = faces_[WEST];
    faces_[WEST] = tmp;
    return;
}
void Dice::roll_to(char d){
    switch(d){
    case 'N':
        roll_north();
        break;
    case 'E':
        roll_east();
        break;
    case 'W':
        roll_west();
        break;
    case 'S':
        roll_south();
        break;
    case 'R':
        roll_right();
        break;
    case 'L':
        roll_left();
        break;
    default:
        break;
    }
    return;
}
 
int Dice::get_cur_label(char f){
    return faces_[f];
}
 
bool Dice::operator==(Dice &r){
    return this->faces_ == r.faces_;
}

int main(int argc, char **argv){
	int n;
	std::vector<int> labels(6);
	for(int i = 0; i < 6; i++){
		labels[i] = i + 1;
	}
	std::string buf;
	int sum = 1;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	//FILE *fp = fopen("test.txt", "r");
#endif

	for(;;){
		Dice d(labels);
#if INPUT_FROM_FILE
		std::getline(ifs, buf);
		n = std::stoi(buf);
#else
		std::getline(std::cin, buf);
		n = std::stoi(buf);
#endif
		if(n == 0){ break; }

		sum = 1;
		for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
			std::getline(ifs, buf);
#else
			std::getline(std::cin, buf);
#endif
			d.roll_to(buf[0]);

			sum += d.get_cur_label(TOP);
		}
		std::cout << sum << std::endl;
	}
	return 0;
}
