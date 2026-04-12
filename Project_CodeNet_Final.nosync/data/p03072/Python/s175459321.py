n = int (input())
h = list(map(int,input().split()))
max_num = 0
ans = 0
for i in range (n):
  if h[i] >= max_num:
    max_num = h[i]
    ans += 1
print(ans)