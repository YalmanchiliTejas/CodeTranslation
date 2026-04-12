n,m=map(int, input().split())
q=[]
for i in range(m):
    a,b=map(int, input().split())
    q+=[[a,b],[b,a]]
p=[[1]]
count=0
while p:
    p1=p.pop()
    if len(p1)==n:count+=1
    else:
        for i,j in q:
            if i == p1[-1] and j not in p1:
                p.append(p1+[j])
    #print(p1,p)
print(count)