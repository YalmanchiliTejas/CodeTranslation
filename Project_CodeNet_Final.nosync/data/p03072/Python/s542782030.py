n = int(input())
h =list(map(int,input().split()))
c = 0
hmax = 0
for i in range(n):
  if hmax <= h[i]:
    c += 1
    hmax = h[i]
print(c)