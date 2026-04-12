n = int(input())
hs = list(map(int, input().split()))

h_max = 0
m = 0

for h in hs:
  if h >= h_max:
    h_max = h
    m += 1

print(m)