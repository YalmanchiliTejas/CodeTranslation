N = int(input())
H = list(map(int, input().split()))

ans = 0
max_H = 0
for h in H:
  if h >= max_H:
    max_H = h
    ans += 1

print(ans)