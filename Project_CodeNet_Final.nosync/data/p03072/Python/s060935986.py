N = int(input())
H = [int(i) for i in input().split()]
maxH = H[0]
total = 1
for h in H[1:]:
  if h >= maxH:
    total += 1
    maxH = h
print(total)