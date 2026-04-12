# n=int(input())
n=int(input())
a=list(map(int,input().split(" ")))
mat=[[(0,0) for i in range(n)] for j in range(n)]
for l in range(1,n+1):
	for i in range(n-l+1):
		j=i+l-1
		# print(i,j)
		# if(i<=j):
		if(i==j):
			x=a[i]
			y=-a[i]
			mat[i][j]=(x,y)
		else:
			# print(i+1)
			x=max(a[i]+mat[i+1][j][1],a[j]+mat[i][j-1][1])
			y=min(-a[i]+mat[i+1][j][0],-a[j]+mat[i][j-1][0])
			mat[i][j]=(x,y)
print(mat[0][n-1][0])
# print(mat)