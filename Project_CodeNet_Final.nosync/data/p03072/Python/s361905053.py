n = int(input())
hs = list(map(int, input().split()))

max_hs = [0]
for h in hs:
  max_hs.append(max(max_hs[-1], h))

count = 0
for h, max_h in zip(hs, max_hs[1:]):
  if h >= max_h:
    count += 1
  
print(count)