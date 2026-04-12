
n,m=map(int, input().split())
q=[]
for i in range(m):
    a,b=map(int, input().split())
    q.append([a,b])
    q.append([b,a])
p=[[1]]
count=0
route=set()
while len(p)!=0:
    p1=p.pop()
    for i,j in q:
        #print(i,j)
        if i == p1[-1]:
            if j not in p1:
                p.append(p1+[j])
    if len(p1)==n: count+=1
    route |= {tuple(p1)}
    #print(p,p1)
print(count)