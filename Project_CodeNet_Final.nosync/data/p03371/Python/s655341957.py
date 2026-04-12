a,b,c,x,y=[int(s) for s in input().split()]
if x<=y:
  A=a
  B=b
  C=c
  X=x
  Y=y
else:
  A=b
  B=a
  C=c
  X=y
  Y=x
#print([Y*2*C,X*2*C+(Y-X)*B,X*A+Y*B])
print(min([Y*2*C,X*2*C+(Y-X)*B,X*A+Y*B]))
