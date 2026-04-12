n = int(input())
l = [int(x) for x in input().split()]
ans = 1
for i in range(1, n):
  if max(l[:i + 1]) == l[i]:
    ans += 1
print(ans)