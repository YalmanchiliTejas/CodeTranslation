N=int(input())
h=list(map(int, input().split()))

m=0
ct=0
for i in range(N):
	if m<=h[i]:
		ct+=1
	m=max(m,h[i])
print(ct)