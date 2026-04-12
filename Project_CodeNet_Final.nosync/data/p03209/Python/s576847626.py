def dfs(i,x):
 if i==0:return 1 if x>0else 0       
 if x<=1+l[i-1]:return dfs(i-1,x-1) 
 return 1+p[i-1]+dfs(i-1,x-2-l[i-1])
n,x=map(int,input().split())
l,p=[1],[1]
for i in range(n):
 l.append(l[i]*2+3)
 p.append(p[i]*2+1)
print(dfs(n,x))