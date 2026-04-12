n=int(input())
l=list(map(int,input().split()))
c=0
for i in l:
	c+=i**2
print(((sum(l)**2-c)//2)%(10**9+7))