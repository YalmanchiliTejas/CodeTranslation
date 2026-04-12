n = int(input())
h  = list(map(int,input().split()))

res = 0
ma = h[0]
for e in h:
  if ma <= e:
    ma = e
    res += 1
print(res)