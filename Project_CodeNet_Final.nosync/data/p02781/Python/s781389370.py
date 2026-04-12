n=input()
ln=len(n)
nn=[-1,-1,-1]
nnn=[0,0,0]
j=0
for i in range(ln):
  if n[i]!="0":
    nn[j]=i
    nnn[j]=int(n[i])
    j+=1
    if j==3:
      break

s=[9*(ln-1),81*(ln-1)*(ln-2)//2,729*(ln-1)*(ln-2)*(ln-3)//6]
s[0]+=nnn[0]
s[1]+=(nnn[0]-1)*9*(ln-1)+(0 if nn[1]==-1 else nnn[1]+9*(ln-nn[1]-1))
s[2]+=(nnn[0]-1)*81*(ln-1)*(ln-2)//2
s[2]+=(0 if nn[1]==-1 else (nnn[1]-1)*9*(ln-nn[1]-1)+81*(ln-nn[1]-1)*(ln-nn[1]-2)//2)+(0 if nn[2]==-1 else nnn[2]+9*(ln-nn[2]-1))

k=int(input())
print(s[k-1])