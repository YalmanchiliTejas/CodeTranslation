N=input()
H=map(int, raw_input().split())

ans=1
for i in range(1,N):
	m=max(H[:i])
	if m<=H[i]:
		ans+=1

print ans
