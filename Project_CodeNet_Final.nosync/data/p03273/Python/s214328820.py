H, W = map(int, raw_input().split())
a = []
for i in range(H):
  a.append(raw_input())
b = [r for r in a if "#" in r]
c = ["".join(r) for r in zip(*b) if "#" in r]
for l in zip(*c):
  print "".join(l)