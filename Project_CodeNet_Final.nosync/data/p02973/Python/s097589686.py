import bisect

n = int(input())
arr = [int(input()) for _ in range(n)]
colors = []

colors.append(arr[-1])
cnum = len(colors)
for a in arr[-2::-1]:
  i = bisect.bisect_right(colors, a)
  if i < cnum:
    colors[i] = a
  else:
    colors.append(a)
    cnum += 1

print(cnum)

