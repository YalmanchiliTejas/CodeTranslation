n = int(input())
h = list(map(int, input().split()))

ans = 1

for i in range(1,len(h)):
  flag = 0
  for j in range(i):
    if h[i] < h[j]:
      flag = 1
  if flag == 0:
    ans += 1
    
print(ans)