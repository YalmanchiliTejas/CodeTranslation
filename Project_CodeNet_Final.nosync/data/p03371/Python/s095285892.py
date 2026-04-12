A,B,C,X,Y = map(int, input().split())
lim = max(X,Y)
ans = float('inf')
for i in range(lim+1):
  ans = min(ans,(i * 2 * C) + max(0,(X - i)) * A + max(0,(Y - i)) * B)
print(ans)