h,w=map(int,input().split())
a=[[0 for j in range(w)] for i in range(h)]
for i in range(h):
  s=input()
  for j in range(w):
    if s[j]==".":
      a[i][j]=0
    else:
      a[i][j]=1
H=[]
for i in range(h):
  if sum(a[i])==0:
    H.append(i)
a2=[[0 for j in range(w)] for i in range(h-len(H))]
key=0
for _ in range(h):
  if _ in H:
    continue
  else:
    for j in range(w):
      a2[key][j]=a[_][j]
    key+=1
Q=[]
S=[0]*w
for j in range(w):
  for i in range(h-len(H)):
    S[j]+=a2[i][j]
for j in range(w):
  if S[j]==0:
    Q.append(j)
key=0


a3=[[0 for j in range(w-len(Q))] for i in range(h-len(H))]
for j in range(w):
  if j in Q:
    continue
  elif j not in Q:
    for i in range(h-len(H)):
      a3[i][key]=a2[i][j]
    key+=1

for i in range(h-len(H)):
  for j in range(w-len(Q)):
    a3[i][j]=str(a3[i][j])
    if a3[i][j]=="0":
      a3[i][j]="."
    elif a3[i][j]=="1":
      a3[i][j]="#"
ans=[""]*(h-len(H))
for i in range(h-len(H)):
  for j in range(w-len(Q)):
    ans[i]+=a3[i][j]
  print(ans[i])
    