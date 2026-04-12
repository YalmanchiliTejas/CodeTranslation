n = int(input())
h = list(map(int,input().split()))
m = 0
a = 0
for i in range(n):
  if m <= h[i]:
    a += 1
    m = h[i]
print(a)