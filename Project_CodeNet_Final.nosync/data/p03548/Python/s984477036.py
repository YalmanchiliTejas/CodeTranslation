X,Y,Z=list(map(int,input().split()))
for i in range(100001):
  if X >= i * Y + ( i + 1 ) * Z:
    ans = i
print(ans)