A,B,C,X,Y=map(int,input().split())
ans=0
if X>Y:
  A,B=B,A
  X,Y=Y,X
if A+B<C*2:
  ans+=(A+B)*X
else:
  ans+=C*X*2

Y-=X
tmp=B*Y
for y in range(Y):
  tmp2=B*y+C*(Y-y)*2
  if tmp > tmp2:
    tmp=tmp2
print(ans+tmp)