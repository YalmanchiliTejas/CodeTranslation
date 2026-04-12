N = int(input())
H = list(map(int, input().split()))

h = -1
ans = 0
for i in H:
  if i >= h:
    ans += 1
  h = max(h, i)
  
print(ans)