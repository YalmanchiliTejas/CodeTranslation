n = int(input())
h = [int(v) for v in input().split()]
total = 1

max_height = h[0]

for i in range(1,n):
  if max_height <= h[i]:
    max_height = h[i]
    total += 1
print(total)