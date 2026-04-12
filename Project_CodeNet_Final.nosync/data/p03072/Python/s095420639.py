n = int(input())
h = list(map(int,input().split()))
ans = 1
for i in range(n):
  cnt = 0
  for j in range(i):
    if h[i]>=h[j]:
      cnt +=1
    if cnt == i:
      ans +=1
print(ans)