h,w=map(int,input().split())
l=[]
for i in range(h):
    l.append(list(input()))
i=0
while i<len(l):
    for j in range(len(l[0])):
        if l[i][j]!='.':
            i+=1
            break
    else:
        del(l[i])

i=0    
while i<len(l[0]):
    for j in range(len(l)):
        if  l[j][i]!='.':
            i+=1
            break
    else:
        for k in range(len(l)):
            del l[k][i]
i=0
for i in range(len(l)):
    s=''
    for j in range(len(l[0])):
        s=s+l[i][j]
    print(s)    