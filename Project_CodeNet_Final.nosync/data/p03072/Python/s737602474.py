n=int(input())
h=list(map(int,input().split()))

max=0
cnt=0

for i in range(n):
	if max <= h[i]:
		cnt+=1
		max=h[i]

print(cnt)