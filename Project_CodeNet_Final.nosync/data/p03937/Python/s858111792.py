h, w = map(int, input().split())
c = 0
for _ in range(h):
  c += input().count("#")
if c == h+w-1:
  print("Possible")
else:
  print("Impossible")