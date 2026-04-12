n = int(input())
hlist = [int(_) for _ in input().split()]

base = hlist[0]
result = 0

for h in hlist:
  if base <= h:
    result = result +1
    base = h

print(result)