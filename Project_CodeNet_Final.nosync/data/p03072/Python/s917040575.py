n = int(input())
hs = list(map(int, input().split()))

maxs = hs[0]
count = 1
for h in hs[1:]:
  if h >= maxs:
    maxs = h
    count += 1

print(count)