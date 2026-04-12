h,w=map(int,input().split())
a=[]
for i in range(h):
    a.append(list(input()))
j=0
lis=[]
l=[]
count=0
for i in range(h):
    for j in range(w):
        if a[i][j]!='.':
            break
        if j==w-1:
            l.append(i)
x=0
while x<len(l):
    del a[l[x]-count]
    count+=1 
    x+=1
#print(a)
for k in range(len(a)):
    for l in range(w):
        if a[k][l]=='.':
            c=0
            while c<len(a):
                if a[c][l]!='.':
                    break
                if c==len(a)-1 and l not in set(lis):
                    lis.append(l)
                c+=1
ans=''
#print(lis)
tmp=0
count=0
for o in range(len(lis)):
    tmp=lis[o]
    for s in range(len(a)):
        del a[s][tmp-count]
    count+=1    
for q in range(len(a)):
    for e in range(len(a[0])):
        ans+=a[q][e]
    print(ans)
    ans=''
