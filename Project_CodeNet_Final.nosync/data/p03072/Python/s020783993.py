N = int(input())
H = map(int, input().split())
m = 0
ans = 0
for h in H:
  if h >= m:
    m = h
    ans += 1
print(ans)