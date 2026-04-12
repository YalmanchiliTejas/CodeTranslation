h,w=map(int,input().split())
A=[input() for i in range(h)]
LR=[]
for i in range(h):
  l=A[i].find("#")
  r=A[i].rfind("#")
  LR.append([l,r])
ans=0
for i in range(1,h):
  if LR[i-1][1]==LR[i][0]:
    ans+=1
print("Possible" if ans==h-1 else "Impossible")