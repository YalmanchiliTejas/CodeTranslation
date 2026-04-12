A,B,C,X,Y = [int(x) for x in input().split()]
mi = min(X,Y)
ans = 0
if mi*C*2<A*mi+B*mi:
  X = X-mi
  Y = Y-mi
  ans = mi*C*2
else:
  print(A*X+B*Y)
  exit()
if X>0:
  if X*C*2<X*A:
    ans += X*C*2
    print(ans)
    exit()
  else:
    ans += X*A
    print(ans)
    exit()
if Y>0:
  if Y*C*2<Y*B:
    ans += Y*C*2
    print(ans)
    exit()
  else:
    ans += Y*B
    print(ans)
    exit()
print(ans)