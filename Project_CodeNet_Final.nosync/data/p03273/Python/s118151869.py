H,W=map(int,input().split())
l=[]
l2=[]

for i in range(H):
    a=list(input())
    if a.count("#")!=0:
        l.append(a)

l1=list(zip(*l))
i=0
while i < len(l1):
    if l1[i].count("#")!=0:
        l2.append(l1[i])
    i+=1
l3=list(zip(*l2))
for i in range(len(l3)):
    print("".join(l3[i]))        
