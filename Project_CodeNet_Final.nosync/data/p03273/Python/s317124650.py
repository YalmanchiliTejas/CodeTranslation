a,b=map(int,input().split(" "))
l=[]
for i in range(a):
    k=list(input())
    l.append(k)
ca=0
for i in range(a):
    for j in range(b):
        if l[i-ca][j]=="." and j+1==b:
            del l[i-ca]
            ca+=1
        elif l[i-ca][j]=="." :
            pass
        else:
            break
cb=0
for i in range(b):
    for j in range(a-ca):
        if l[j][i-cb]=="." and j+1==a-ca:
            for k in range(a-ca):
                del l[k][i-cb]
            else:
                cb+=1
        elif l[j][i-cb]==".":
            pass
        else:
            break
        
for i in l:
    print(*i,sep="")
    