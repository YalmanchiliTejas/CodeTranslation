a=input().split()
X=int(a[0])
Y=int(a[1])
Z=int(a[2])
p=int( X/(Y+Z) )
q=int( X%(Y+Z) )
if( q>=Z ):
 print(p)
else:
 print(p-1)