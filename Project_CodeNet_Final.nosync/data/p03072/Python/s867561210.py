n=int(input())
h=list(map(int,input().split()))
cnt=1
maxh=h[0]
for i in range(1,n):
	if maxh<=h[i]:
		maxh=h[i]
		cnt+=1
print(cnt)