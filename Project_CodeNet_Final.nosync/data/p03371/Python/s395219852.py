A,B,AB,X,Y = [int(x) for x in input().split()]
total = A*X+B*Y
for xy in range(0,max(X,Y)+1):
  x = X-xy
  y = Y-xy
  if x<0:
    x=0
  if y<0:
    y=0
  if x*A+y*B+xy*2*AB < total:
    total = x*A+y*B+xy*2*AB
    #print(x,y,xy)
print(total)