A,B,C,X,Y=map(int,input().split())
v=10**10
for i in range(0,max(X,Y)*2+2):
  v=min(v,A*max(X-i,0)+B*max(Y-i,0)+C*i*2)

print(v)