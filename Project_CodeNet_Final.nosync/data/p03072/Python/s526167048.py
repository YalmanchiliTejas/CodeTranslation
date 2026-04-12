n = int(input())
h = list(map(int, input().split()))

k = 0
for i in range(n):
  if max(h[:i+1]) == h[i]:
    k = k + 1
print(k)