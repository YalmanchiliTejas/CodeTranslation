n = int(input())
h = list(map(int, input().split()))
lis = [h[0]]
ans = 1
for i in range(1,n):
  if h[i] >= max(lis):
    ans += 1
  lis.append(h[i])
  
print(ans)