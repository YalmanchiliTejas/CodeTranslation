N=int(input())
H=input().split()
H=[int(i) for i in H]
ans,ma=0,H[0]
for i in H:
	if ma<=i:
		ans+=1
		ma=i
print(ans)