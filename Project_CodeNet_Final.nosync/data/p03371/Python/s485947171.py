A,B,C,X,Y = map(int,input().split())
if A<C  and B<C:
  print(A*X+B*Y)
  
elif C<=A and C<=B:
  if X<=Y:
    a = 2*C*X+(Y-X)*B
    b = 2*C*Y 
    print(min(a,b))
  else:
    a = 2*C*Y+(X-Y)*A
    b = 2*C*X
    print(min(a,b))
    
elif A<=C and B>=C:
  if X<=Y:
    a = 2*C*X+(Y-X)*B
    b = A*X +B*Y
    print(min(a,b))
  else:
    a = 2*C*Y+(X-Y)*A
    b = A*X +B*Y
    print(min(a,b))
else:
  if X<=Y:
    a = 2*C*X+(Y-X)*B
    b = A*X +B*Y
    print(min(a,b))
  else:
    a = 2*C*Y+(X-Y)*A
    b = A*X +B*Y
    print(min(a,b))