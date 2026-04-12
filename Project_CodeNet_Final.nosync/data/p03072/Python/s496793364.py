n = int(input())
h = list(map(int, input().split()))
mx = h[0]
c = 1
for i in range(1,n):
  if mx <= h[i]:
    c += 1
    mx = h[i]
print(c)
