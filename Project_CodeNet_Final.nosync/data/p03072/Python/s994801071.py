n = int(input())
H = [int(x) for x in input().split()]
m = -1
cc = 0
for h in H:
  cc += (h >= m)
  m = max(h, m)
print(cc)