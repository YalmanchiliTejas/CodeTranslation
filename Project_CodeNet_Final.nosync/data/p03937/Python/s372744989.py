H,W=map(int,input().split())
A=[]
for i in range(H):
  A.append(input())
#print(A)

sw=0
for i in range(H):
  tmp=0
  for j in range(W-1):
    if A[i][j]=="#" and A[i][j+1]==".":
      tmp=1
    if tmp==1 and A[i][j]=="." and A[i][j+1]=="#":
      sw=1
#print(sw)

if sw==1:
  print("Impossible")
else:
  l=[]
  r=[]
  for i in range(H):
    ll=0
    for j in range(W-1):
      if A[i][j]=="." and A[i][j+1]=="#":
        ll=j+1
        break
    l.append(ll)
    
    rr=W-1
    for j in range(W-1):
      if A[i][j]=="#" and A[i][j+1]==".":
        rr=j
        break
    r.append(rr)
#  print(l)
#  print(r)

  sw2=0
  for i in range(len(r)-1):
    if r[i]!=l[i+1]:
      sw2=1
  print("Impossible" if sw2==1 else "Possible")