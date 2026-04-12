N = int(input())
H_list = list(map(int, input().split()))

max_h = 0
ans = 0
for i in range(N):
  if max_h <= H_list[i]:
    ans += 1
  max_h = max(max_h, H_list[i])
  
print(ans)