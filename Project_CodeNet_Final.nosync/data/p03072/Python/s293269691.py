n = int(input())
h = [int(i) for i in input().split()]

ans = 1
max = h[0]
for i in range(1, n):
  if h[i] >= max:
    max = h[i]
    ans += 1

print(ans)