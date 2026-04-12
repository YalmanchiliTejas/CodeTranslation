S = input().strip() ; 
s1 = set() ;

for s in S :
	s1.add ( s ) ; 

p = "Yes" if len(s1) >= 2 else "No" 
print ( p ) ;