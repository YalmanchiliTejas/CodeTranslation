h, w = map(int, input().split())
l = []
r = []

for i in range(h):
    ls = list(input())
    if "#" in ls:
        l.append(ls)
        

s = [0]*w

for i in range(len(l)):
  for j in range(w):
    if l[i][j] == "#":
      s[j] = 1  

for i in range(len(l)):
  ans = ""
  for j in range(w):
    ans += l[i][j]*s[j]
  print(ans)

