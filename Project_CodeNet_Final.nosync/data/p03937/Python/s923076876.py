h, w = map(int, input().split())
s = [input() for _ in range(h)]
cnt = 0
for i in range(h):
  cnt += s[i].count("#")
if cnt == h+w-1:
  print("Possible")
else:
  print("Impossible")