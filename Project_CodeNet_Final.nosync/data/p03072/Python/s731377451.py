n = int(input())
a = [int(i) for i in input().split()]

ans = 0
for i in range(n):
  if max([0]+a[:i]) <= a[i]:
    ans += 1

print(ans)