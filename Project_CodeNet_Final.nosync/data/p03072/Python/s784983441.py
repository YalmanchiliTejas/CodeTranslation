n = int(input())
a = list(map(int, input().split()))
ans = 0
max_ = a[0]
for i in a:
  if max_ <= i:
    max_ = i
    ans += 1
print(ans)