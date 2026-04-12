N=int(input())
H=list(map(int,input().split()))

c=0

for i in range(N):
	if max(H[0:i+1])==H[i]: c+=1

print(c)