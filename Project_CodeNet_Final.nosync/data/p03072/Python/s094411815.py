N = int(input())
H = list(map(int,input().split()))

ans, max_height = 0, 0

for h in H:
  if h >= max_height:
    ans += 1
    max_height = h
print(ans)