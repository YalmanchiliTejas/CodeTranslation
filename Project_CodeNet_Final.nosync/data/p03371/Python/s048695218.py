A, B, C, X, Y = map(int, input().split())
if C*2>=A+B:
  ans = A*X+B*Y
else:
  ans = min(C*2*max(X,Y),C*2*min(X,Y)+A*max(0,X-Y)+B*max(0,Y-X))
print(ans)