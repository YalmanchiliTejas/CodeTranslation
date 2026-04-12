n = int(input())
h = [int(i) for i in input().split(" ")]

r = 1
for i in range(1, n, 1):
  if max(h[0:i]) <= h[i]:
    r += 1

print(r)