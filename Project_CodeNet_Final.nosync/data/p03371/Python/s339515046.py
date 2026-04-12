A,B,C,X,Y = map(int, input().split())
Z = X-Y
if Z<0:
  AB_least = min([X,Y])*2*C + abs(Z)*B
else:
  AB_least = min([X,Y])*2*C + Z*A
AB_all = max([X,Y])*2*C
AandB = A*X + B*Y
ans = min([AB_least,AB_all,AandB])
print(ans)