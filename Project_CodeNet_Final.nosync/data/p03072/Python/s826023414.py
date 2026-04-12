N=int(input())
H=list(map(int,input().split()))
ans,ma=0,H[0]
for i in H:
	if ma<=i:
		ans+=1
		ma=i
print(ans)
