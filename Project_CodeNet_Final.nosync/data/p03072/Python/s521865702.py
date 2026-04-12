n = int(input())
h = list(map(int, input().split()))
m = 0
c = 0
for i in range(n):
  if h[i] >= m:
    c += 1
    m = h[i]
print(c)