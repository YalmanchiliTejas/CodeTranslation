n = int(input())
h = list(map(int, input().split()))
ans = 0

for i in range(n):
  for j in range(i):
    if h[i] < h[j]:
      ans+=1
      break
      
print(n - ans)