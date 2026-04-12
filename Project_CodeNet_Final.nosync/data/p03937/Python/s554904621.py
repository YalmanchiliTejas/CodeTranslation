h,w = map(int,input().split())

f = 1
k = 0
p = 0
for _ in range(h):
  s = input()
  k += s.count("#")
  if s[p] == ".":
    f = 0
    break
  else:
    for i in range(p,w):
      if s[i] == ".":
        break
      else:
        p = i

if f == 1 and k == h+w-1:
  print("Possible")
else:
  print("Impossible")
  
 