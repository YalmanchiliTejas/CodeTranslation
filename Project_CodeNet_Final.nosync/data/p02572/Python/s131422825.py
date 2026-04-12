n=int(input())
a=list(map(int,input().split()))
sum1 = sum(a)
ans=0
for x in a:
	sum1-=x;
	ans+= (x*sum1)
	# print(ans)
print(ans%1000000007)
