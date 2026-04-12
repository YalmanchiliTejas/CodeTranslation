n = int(input())
l = list(map(int, input().split(' ')))
ans = 0
h = l[0]
for t in l:
  if t >= h:
    ans += 1
    h = t
print(ans)