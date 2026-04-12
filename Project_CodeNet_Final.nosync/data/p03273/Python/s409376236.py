import sys
h,w=map(int,input().split())

b=[]
d=[]
k=0
for i in range(w):
    d.append(i)

for i in range(h):
    a=input()
    if a!="."*w:
        b.append(a)
    else:
        h-=1
        
for i in range(w):
    c=0
    for j in range(h):
        if b[j][i]=="#":
            c+=1
    if c==0:
        del(d[k])
    else:
        k+=1
            
for i in range(h):
    for j in d:
       sys.stdout.write(b[i][j]) 
    print("")
            