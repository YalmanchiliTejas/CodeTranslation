h,w=map(int, input().split())
s=[list(input()) for _ in range(h)]
c=0
for i in range(h):
  for j in range(w):
    if s[i][j]=="#":
      c+=1
if c==h+w-1:
  print("Possible")
else:
  print("Impossible")
