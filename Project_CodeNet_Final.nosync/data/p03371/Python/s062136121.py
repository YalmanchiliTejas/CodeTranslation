A, B, C, X, Y = map(int, input().split())
total = 0
ans = 10**10

for i in range(0, max(X, Y)*2+2, 2):
  total = A*(max(X-(i/2),0)) + B*(max(Y-(i/2),0)) + C*i
  # print(total)
  ans = min(ans, total)
  
print(int(ans))