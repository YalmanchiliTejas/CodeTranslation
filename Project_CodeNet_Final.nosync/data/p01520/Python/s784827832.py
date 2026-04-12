n,t,e=map(int,raw_input().split())
x=map(int,raw_input().split())

for i in range(0,n):
	if t%x[i]<=e or t%x[i]>=x[i]-e:
		print i+1
		exit(0)

print -1