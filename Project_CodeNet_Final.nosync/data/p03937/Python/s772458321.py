h, w = map(int, input().split())
c = [input() for i in range(h)]
s=0

for i in range(h):
  for j in range(w):
    if c[i][j]=="#":
      s+=1
      
a = 1
x = 0
y = 0

while a<s:
  flg = True
  while x+1<w and c[y][x+1]=="#":
    x+=1
    a+=1
    flg = False
  while y+1<h and c[y+1][x]=="#":
    y+=1
    a+=1
    flg = False
  if flg:
    break
if a==s:
  print("Possible")
else:
  print("Impossible")


  
    