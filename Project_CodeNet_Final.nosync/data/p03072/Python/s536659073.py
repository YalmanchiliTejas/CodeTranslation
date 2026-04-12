n = int(input())
h = list(map(int, input().split()))

ans = 0
res = h[0]

for i in h:
  if i >= res:
    ans += 1
    res = i
print(ans)