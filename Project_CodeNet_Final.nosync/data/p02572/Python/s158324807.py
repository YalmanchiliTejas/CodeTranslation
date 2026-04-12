N = int( input().strip() ) ; 
arr = list ( map  ( int , input().strip().split(" ") ) ) ; 


mod = pow ( 10,  9 ) + 7 ;

arr2 = [ 0 for x in range ( N ) ] ;
for x in range ( N -1 , 0 , -1 ) :
	if x == N -1  :
		arr2[x] = arr[x] ; 
	else :
		arr2[x] = ( arr[x] + arr2[x+1] ) % mod ;
t = 0 ; 
for x in range ( N -1 ) : 
	t += ( arr[x] * arr2[x+1] ) % mod ;
	t %= mod ; 
print ( t ) ;
