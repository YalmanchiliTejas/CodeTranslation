n = int(input())
lst = list(map(int, input().split()))

peak = 0
ans = 0
for i in range(n):
  if lst[i] >= peak:
    peak = lst[i]
    ans += 1
print(ans)