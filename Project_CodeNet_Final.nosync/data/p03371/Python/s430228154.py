A,B,C,X,Y=map(int,input().split())
anlist=[]
for i in range(10**5+1):
  ans=2*C*i+A*max(0,X-i)+B*max(0,Y-i)
  anlist.append(ans)
print(min(anlist))