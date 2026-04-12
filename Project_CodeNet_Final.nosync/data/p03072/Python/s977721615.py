n=int(input())
listh = [int(i) for i in input().split()]

ans=1

temp=listh[0]
if n>=2:
	for i in range(1,n):
		if temp<=listh[i]:
			ans=ans+1
			temp=listh[i]
	#		print(temp)
print(ans)