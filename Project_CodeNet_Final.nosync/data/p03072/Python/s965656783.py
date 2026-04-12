N=int(input())
H=list(map(int,input().split()))
count=1
d=H[0]
for i in range(1,N):
	if d<=H[i]:
		count=count+1
		d=H[i]
print(count)