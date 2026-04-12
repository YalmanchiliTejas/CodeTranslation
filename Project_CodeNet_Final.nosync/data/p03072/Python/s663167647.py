n=int(raw_input())
h=list(map(int,raw_input().split()))
ctr=1
for i in range(1,n):
	if h[i]>=max(h[:i]):
		ctr+=1
print ctr
