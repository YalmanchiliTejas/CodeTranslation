h, w = map(int, input().split())
l = []
r = []

for i in range(h):
    ls = list(input())
    if "#" in ls:
        l.append(ls)
        for j in range(w):
            if ls[j] == "." and j not in r:
                r.append(j)

s = [i for i in range(w)]

for i in r:
  count = 0
  for j in range(len(l)):
    if l[j][i] == ".":
      count += 1
  if count == len(l):
    s.remove(i) 

ans = []
for i in range(len(l)):
  a = []
  for j in s:
    a.append(l[i][j])
  ans.append(a)
  

for i in range(len(l)):
  b = "".join(ans[i])
  print(b)
  

