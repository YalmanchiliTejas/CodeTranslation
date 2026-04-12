h,w = map(int,input().split())
l = []
for i in range(h):
  x = list(input())
  if "#" in x:
    l.append(x)

for j in range(w):
  if all(l[k][j] == "." for k in range(len(l))):
    for k in range(len(l)):
      l[k][j] = ""
for m in range(len(l)):
  print(''.join(l[m]))