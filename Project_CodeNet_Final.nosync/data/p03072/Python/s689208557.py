n = int(input())
a = list(map(int, input().split()))
now = a[0]
ans = 1
for i in a[1:]:
  if i >= now:
    ans += 1
    now = i
print(ans)
