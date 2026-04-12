#include<iostream>

int main(void)
{
	int a, b;
	std::cin >> a >> b;
	if( a > b ) std::cout << "a > b" << std::endl;
	else if(a < b ) std::cout << "a < b" << std::endl;
	else if( a == b ) std::cout << "a == b" << std::endl;

	return 0;
}

/*

#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<string>

#define EPS 1e-5
#define PI 3.141592654

class Point{
	double x;
	double y;
public:
	Point( double a , double b ):x(a),y(b){}
	double X() const{ return x; }
	double Y() const{ return y; }
	double Norm() const{ return sqrt( pow( x , 2 ) + pow( y , 2 ) ); }
};

typedef Point Vector;

class Circle{
	Point o;
	double r;
public:
	Circle( double x , double y , double rad ):o(x,y),r(rad){}
	Point O(){ return o; }
	double R(){ return r; }
};

double getDistance(const Point& a, const Point& b)
{
	return sqrt( pow(a.X() - b.X() , 2) + pow(a.Y() - b.Y() , 2));
}

double getAreaOfTri( const Point& a , const Point& b , const Point& c )
{
	double ab = getDistance( a , b );
	double bc = getDistance( b , c );
	double ca = getDistance( c , a );
	double s = ( ab + bc + ca ) / 2.0;
	double Area = sqrt( s * (s - ab) * (s - bc) * (s - ca) );
	if(s - ab < EPS || s - bc < EPS || s - ca < EPS){
		Area = 0;
	}
	return Area;
}

double getDistancePointLine( const Point& o , const Point& a , const Point& b )
{
	double area = getAreaOfTri( o , a , b );
	double ab = getDistance( a , b );
	double h = 2 * area / ab;
	return h;
}

Point getMiddlePoint( const Point& a , const Point& b )
{
	double middleX = (a.X() + b.X()) / 2.0;
	double middleY = (a.Y() + b.Y()) / 2.0;
	Point middle( middleX , middleY );
	return middle;
}

double getDotProduct( const Vector& a , const Vector& b )
{
	return a.X() * b.X() + a.Y() * b.Y();
}

double getAngle( const Vector& a , const Vector& b )
{
	double cosAngleAB = getDotProduct( a , b ) / ( a.Norm() * b.Norm() );
	if( cosAngleAB < 0 ){
		cosAngleAB += EPS;
	}
	else if( cosAngleAB > 0 ){
		cosAngleAB -= EPS;
	}
	double angleAB = acos( cosAngleAB );
	return angleAB;
}

bool isWall( const Point& t , const Point& s , Circle wall )
{
	Vector ts( s.X() - t.X() , s.Y() - t.Y() );
	Vector to( wall.O().X() - t.X() , wall.O().Y() - t.Y() );
	Vector st( t.X() - s.X() , t.Y() - s.Y() );
	Vector so( wall.O().X() - s.X() , wall.O().Y() - s.Y() );

	double angleOTS = getAngle( ts , to );
	double angleOST = getAngle( st , so );

	// 壁になるときにtrueを返す。
	if( wall.R() > getDistance( t , wall.O() ) && wall.R() > getDistance( s , wall.O() ) ){
		return false;
	}
	else if( wall.R() < getDistance( t , wall.O() ) && wall.R() < getDistance( s , wall.O() ) ){
		if( !(angleOTS < PI/2  && angleOST < PI/2  && getDistancePointLine( wall.O() , t , s ) <= wall.R() + EPS ) ){
			return false;
		}
	}
	else{
		return true;
	}
}

int main(void)
{
	int n, m;
	// std::vector<Circle> wall;
	while(1){
		std::vector<Circle> wall;
		std::cin >> n;

		if( n == 0 ){
			break;
		}
		for( int i = 0 ; i < n ; i++ ){
			int x, y, r;
			std::cin >> x >> y >> r;

			// x = 6; y = 6; r = 3;

			Circle cir( x , y , r );
			wall.push_back(cir);
		}
		std::cin >> m;

		for( int i = 0 ; i < m ; i++ ){
			int tx, ty, sx, sy;
			std::cin >> tx >> ty >> sx >> sy;

			Point t(tx, ty);
			Point s(sx, sy);
			int flag = 0;
			for( int j = 0 ; j < n ; j++ ){
				if( isWall( t , s , wall[j] ) ){
					flag = 1;
					break;
				}
			}
			std::cout << (flag == 1 ? "Safe":"Danger") << std::endl;
		}
	}

	return 0;
}

*/