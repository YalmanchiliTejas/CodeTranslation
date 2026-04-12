H,W=map(int,input().split())
prev=0
for i in range(H):
  s=input()
  id = s.index("#")
  if id >= prev:
    flag=False
    prev = W-1 - s[::-1].index("#")
    for j in range(id,W):
      if flag and s[j]=="#":
        print("Impossible")
        exit(0)
      if s[j]==".":
        flag=True
  else:
    print("Impossible")
    exit(0)
print("Possible")
  