h,w = map(int,input().split())
l = []
for i in range(h):
  x = list(input())
  if "#" in x:
    l.append(x)
for j in range(w):
  if all(l[i][j] == "." for i in range(len(l))):
    for i in range(len(l)):
      l[i][j] = ""
for i in range(len(l)):
  print(''.join(l[i]))