A,B,C,X,Y = map(int, input().split())
ans = A*X+B*Y
for i in range(max(X,Y)+1):
  ans = min(ans, A*max(X-i,0)+B*max(Y-i,0)+C*i*2)
print(ans)
