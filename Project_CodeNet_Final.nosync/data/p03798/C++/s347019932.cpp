#include <iostream>
#include <string>
using namespace std;

enum Animal {
	S,
	W
};

Animal oppositeAnimal( const Animal a ) {
	return  static_cast<Animal>(static_cast<int>(a) ^ 1);
}


string s;
int n;
Animal *animal_array;
Animal first_animal;

bool recursion( int depth ) {
	
	string str;
	Animal animal_this;
	
	// 自分の発言(o or x)
	str = s.substr( depth, 1 );
	
	// １つ前の発言による、自分のAnimal
	animal_this = animal_array[depth];
	
	// 終端チェック
	if ( depth ==  n-2 )
	{
		if ( animal_this == S )
		{
			// oなら両端が同じAnimal
			if ( str == "o" ) {
				if (animal_array[depth-1] != animal_array[depth+1] ) { return false; }
			}
			// xなら両端が違うAnimal
			else {
				if ( oppositeAnimal(animal_array[depth-1]) != animal_array[depth+1] ) { return false; }
			}
		}
		// 自分が狼なら
		else
		{
			// oなら両端が違うAnimal
			if ( str == "o" ) {
				if ( oppositeAnimal( animal_array[depth-1] ) != animal_array[depth+1] ) { return false; }
			}
			// xなら両端が同じAnimal
			else {
				if (animal_array[depth-1] != animal_array[depth+1] ) { return false; }
			}
		}
	}
	
	
	if ( depth ==  n-1 )
	{
		if ( animal_this == S )
		{
			// oなら両端が同じAnimal
			if ( str == "o" ) {
				return (animal_array[depth-1] == first_animal );
			}
			// xなら両端が違うAnimal
			else {
				return ( oppositeAnimal(animal_array[depth-1]) == first_animal );
			}
		}
		// 自分が狼なら
		else
		{
			// oなら両端が違うAnimal
			if ( str == "o" ) {
				return ( oppositeAnimal( animal_array[depth-1] ) == first_animal );
			}
			// xなら両端が同じAnimal
			else {
				return (animal_array[depth-1] == first_animal );
			}
		}
	}
	
	
	// １つ前のAnimalとの整合性をチェックし、次のAnimalを決定
	// 自分が羊なら
	if ( animal_this == S )
	{
		// oなら両端が同じAnimal
		if ( str == "o" ) {
			animal_array[depth+1] = animal_array[depth-1];
		}
		// xなら両端が違うAnimal
		else {
			animal_array[depth+1] = oppositeAnimal( animal_array[depth-1] );
		}
	}
	// 自分が狼なら
	else
	{
		// oなら両端が違うAnimal
		if ( str == "o" ) {
			animal_array[depth+1] = oppositeAnimal( animal_array[depth-1] );
		}
		// xなら両端が同じAnimal
		else {
			animal_array[depth+1] = animal_array[depth-1];
		}
	}
	
	return recursion( depth + 1 );
}





int main() {
	
	string str_answer = "";
	
	cin >> n;
	cin >> s;
	
	animal_array = new Animal[n];
	
	// 0番目が羊
	animal_array[0] = S;
	first_animal = S;
		// 0番目が"o"
		if ( s.substr( 0, 1 ) == "o" ) {
			// どちらも羊
			animal_array[1] = S;
			animal_array[n-1] = S;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
			
			// どちらも狼
			animal_array[1] = W;
			animal_array[n-1] = W;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
		}
		// 0番目が"x"
		else {
			// 1番目が羊最後が狼
			animal_array[1] = S;
			animal_array[n-1] = W;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
			
			// 1番目が狼最後が羊
			animal_array[1] = W;
			animal_array[n-1] = S;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
		}
	
	// 0番目が狼
	animal_array[0] = W;
	first_animal = W;
		// 0番目が"o"
		if ( s.substr( 0, 1 ) == "o" ) {
			// 1番目が羊最後が狼
			animal_array[1] = S;
			animal_array[n-1] = W;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
			
			// 1番目が狼最後が羊
			animal_array[1] = W;
			animal_array[n-1] = S;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
		}
		// 0番目が"x"
		else {
			// どちらも羊
			animal_array[1] = S;
			animal_array[n-1] = S;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
			// どちらも狼
			animal_array[1] = W;
			animal_array[n-1] = W;
			
			// 正解がみつかれば出力
			if (  recursion( 1 ) ) {
				for ( int i = 0; i < n; i++ ) {
					 str_answer += ( animal_array[i] == S ) ? "S" : "W";
				}
				cout << str_answer << endl;
				delete[] animal_array;
				return 0;
			}
		}
	
	// みつからない
	cout << -1 << endl;
	
	return 0;
}