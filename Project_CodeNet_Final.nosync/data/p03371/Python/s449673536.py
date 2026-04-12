import math

A,B,C,X,Y=map(int,input().split())
limit=max(2*X,2*Y)

ans=float('inf')
#L=[]
for i in range(limit+1):
    temp=C*i+A*math.ceil(max(0,X-i/2))+B*math.ceil(max(0,Y-i/2))
    #L.append(temp)
    ans=min(ans,temp)

print(ans)
#print(L)
