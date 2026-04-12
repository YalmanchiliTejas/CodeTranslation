A,B,C,X,Y = map(int,input().split())
tmp1 = A*X+B*Y
tmp2 = C*max(X,Y)*2
if X<Y:
  tmp3 = C*X*2+B*(Y-X)
else:
  tmp3 = C*Y*2+A*(X-Y)
print(min(tmp1,tmp2,tmp3))