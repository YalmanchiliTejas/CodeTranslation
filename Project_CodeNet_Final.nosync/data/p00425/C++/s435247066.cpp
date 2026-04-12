#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;

enum POS{
	P_TOP,
	P_BOTTOM,
	P_EAST,
	P_WEST,
	P_NORTH,
	P_SOUTH
};

enum ROLL{
	R_WEST,
	R_EAST,
	R_NORTH,
	R_SOUTH,
	R_LEFT,
	R_RIGHT
};

map<int,POS> roll_map;

void roll(POS *dice,ROLL r,int &score){
	for(int i = 0;i < 3;i++){
		dice[i] = roll_map[ (int)dice[i] *10 +  (int)r ];
		if(dice[i] == P_TOP){
			score += i + 1;
		}else if(dice[i] == P_BOTTOM){
			score += 6 - i;
		}
	}
}

int main(){
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_WEST ,P_WEST  ) );
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_EAST ,P_EAST  ) );
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_NORTH,P_NORTH ) );
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_SOUTH,P_SOUTH ) );
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_RIGHT,P_TOP   ) );
	roll_map.insert( map<int,POS>::value_type((int) P_TOP * 10 + R_LEFT ,P_TOP   ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_WEST ,P_EAST  ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_EAST ,P_WEST  ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_NORTH,P_SOUTH ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_SOUTH,P_NORTH ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_RIGHT,P_BOTTOM   ) );
	roll_map.insert( map<int,POS>::value_type((int) P_BOTTOM * 10 + R_LEFT ,P_BOTTOM   ) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_WEST ,P_BOTTOM ) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_EAST ,P_TOP ) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_NORTH,P_WEST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_SOUTH,P_WEST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_RIGHT,P_NORTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_WEST * 10 + R_LEFT ,P_SOUTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_WEST ,P_TOP) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_EAST ,P_BOTTOM) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_NORTH,P_EAST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_SOUTH,P_EAST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_RIGHT,P_SOUTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_EAST * 10 + R_LEFT ,P_NORTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_WEST ,P_NORTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_EAST ,P_NORTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_NORTH,P_BOTTOM) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_SOUTH,P_TOP) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_RIGHT,P_EAST   ) );
	roll_map.insert( map<int,POS>::value_type((int) P_NORTH * 10 + R_LEFT ,P_WEST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_WEST ,P_SOUTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_EAST ,P_SOUTH) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_NORTH,P_TOP) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_SOUTH,P_BOTTOM) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_RIGHT,P_WEST ) );
	roll_map.insert( map<int,POS>::value_type((int) P_SOUTH * 10 + R_LEFT ,P_EAST  ) );

	string read_s;
	int read_i;
	list<int> score_list;
	while(1){
		cin>>read_i;
		if(read_i == 0){
			break;
		}
		int score = 1;
		POS dice[3] = { P_TOP, P_SOUTH, P_EAST };
		for(int i = 0;i < read_i;i++){
			cin>>read_s;
			ROLL r;
			if(read_s == "West") r = R_WEST;
			if(read_s == "East") r = R_EAST;
			if(read_s == "North") r = R_NORTH;
			if(read_s == "South") r = R_SOUTH;
			if(read_s == "Left") r = R_LEFT;
			if(read_s == "Right") r = R_RIGHT;
			roll(dice,r,score);
		}
		score_list.push_back(score);
	}
	for(auto it = score_list.begin();it != score_list.end(); it++){
		cout<<(*it)<<endl;
	}
	return 0;
}