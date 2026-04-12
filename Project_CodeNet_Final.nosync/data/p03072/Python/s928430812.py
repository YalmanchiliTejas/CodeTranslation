n = int(input())
mountains = [int(_) for _ in input().split()]

curr = 0
tot = 0
for i in mountains:
  if i >= curr:
    tot += 1
    curr = i

print(tot)
  