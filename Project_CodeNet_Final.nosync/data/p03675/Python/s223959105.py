n=int(input())
a=[int(i) for i in input().split()]
ans=[]
for i in range(0,n,2):
	ans.append(a[i])
ans.reverse()
for i in range(1,n,2):
	ans.append(a[i])
#print(ans)
if(n%2==0):
	for i in range(n):
		print(ans[n-i-1],end="")
		if(not i==n-1):
			print(" ",end="")
else:
	for i in range(n):
		print(ans[i],end="")
		if(not i==n-1):
			print(" ",end="")