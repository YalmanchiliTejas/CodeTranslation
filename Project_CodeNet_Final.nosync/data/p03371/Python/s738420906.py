A, B, C, X, Y = map(int, input().split())

ans = 10 ** 9
for i in range(0,max(X,Y)*2+1,2):
  p = i * C + A * max(X - i // 2, 0) + B * max(Y - i // 2, 0)
#  print (i,max(X - i // 2, 0),max(Y - i // 2, 0),p,ans)
  ans = min(ans, p)
print (ans)