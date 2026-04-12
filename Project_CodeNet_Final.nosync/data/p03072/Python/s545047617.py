n = input()
arr = [int(item) for item in input().split()]
mh = 0
c = 0
for i in arr:
  if mh <= i:
    c += 1
    mh = i
print(c)