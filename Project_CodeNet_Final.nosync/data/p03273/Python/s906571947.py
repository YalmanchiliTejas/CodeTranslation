import sys
h,w = map(int,input().split())
square = [input() for i in range(h)]
y = "." * w
ans = []
index = []
for s in square:
  if s != y:
    ans.append(s)
h = len(ans)
for i in range(w):
  dot = 0
  for a in ans:
    if a[i] == ".":
      dot += 1
  if dot == h:
    index.append(i)

if len(index) == 0:
  for a in ans:
    print(a)
else:
  for a in ans:
    f = []
    for i,l in enumerate(a):
      if i not in index:
        f.append(l)
    print("".join(f))



