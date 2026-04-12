A,B,C,X,Y=map(int,input().split())
ans=A*X+B*Y
for i in range(max(X,Y)+1):
	ans=min(ans,2*C*i+A*max((X-i),0)+B*max((Y-i),0))

print(ans)