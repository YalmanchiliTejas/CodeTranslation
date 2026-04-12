n=int(input())
x=list(map(int,input().split()))

lft=x[0]

y=x[1:]

res=1

for i in range(n-1):
	if y[i]>=lft:
		lft=y[i]		
		res+=1

print(res)