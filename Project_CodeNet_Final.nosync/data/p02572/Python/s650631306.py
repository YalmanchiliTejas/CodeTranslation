s =0
r =0

n = int(input())
l = list( map( int , input().split() ))

for e in l:
	r += e*s
	s += e

mod =int(1e9+7)
print( r %mod )