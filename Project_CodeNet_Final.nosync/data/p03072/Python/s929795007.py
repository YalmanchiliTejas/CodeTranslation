N = int(input())
H = list(map(int,input().split()))

max_height = []

for i in range(N):
  if i == 0:
    max_height.append(H[i])
  else:
    max_height.append(max(max_height[-1], H[i]))
    
ans = 0
    
for i in range(N):
  if H[i] >= max_height[i]:
    ans += 1
    
print(ans)