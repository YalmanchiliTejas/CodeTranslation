A,B,C,X,Y = map(int,input().split())
ans = float("inf")
for i in range(max(X,Y) + 1):
  total = A * max(0,X - i) + B * max(0,Y - i) + C * 2 * i
  ans = min(ans,total)
print(ans)