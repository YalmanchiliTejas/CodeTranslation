n=int(input())
H=list(map(int,input().split()))

res=0

for i in range(n-1,-1,-1):
	cnt=0	
	for j in range(0,i):
		if H[i]<H[j]:
			cnt=1
	if cnt==0:
		res+=1

print(res)