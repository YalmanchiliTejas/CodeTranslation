h,w=map(int,input().split())
a=[]
for i in range(h):
    li=str(input())
    if len(set(li))!=1:
        a.append(li)
    elif len(set(li))==1 and li[0]=="#":
        a.append(li)
      
cnt=[]
b=[]
for j in range(w):
    for k in range(len(a)):
        b.append(a[k][j])
    if len(set(b))==2: 
      cnt.append(j)
    elif len(set(b))==1:
      if b[0]=="#":
        cnt.append(j)       
    b=[]            
ans=""
for m in range(len(a)):
  for l in cnt:
    ans+=a[m][l]
  print(ans)
  ans=""