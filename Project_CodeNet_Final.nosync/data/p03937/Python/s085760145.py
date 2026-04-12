h,w=map(int,input().split())
s=[list(input())for _ in range(h)]
ok=[w*[0]for _ in range(h)]
ok[0][0]=1
for i in range(h):
  for j in range(w):
    if i==0:
      if j!=0:
        if s[i][j]=="#":ok[i][j]=ok[i][j-1]
    else:
      if s[i][j]=="#":ok[i][j]|=ok[i-1][j]
      if j==0:continue
      if s[i][j]=="#":ok[i][j]|=ok[i][j-1]
co=sum(i.count("#")for i in s)
if co!=h+w-1:print("Impossible")
elif ok[-1][-1]:print("Possible")
else:print("Impossible")