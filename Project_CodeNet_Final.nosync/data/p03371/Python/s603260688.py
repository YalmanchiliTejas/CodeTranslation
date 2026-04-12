A, B, C, X, Y = map(int, input().split())

ans = 0

ans += min(X, Y) * min(A+B,2*C)

if(X<Y):
  ans += (Y-X)*min(B,2*C)
else:
  ans += (X-Y)*min(A,2*C)
  
print(ans)