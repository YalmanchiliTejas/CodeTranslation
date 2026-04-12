n,t,e = map(int,raw_input().split())
x = map(int,raw_input().split())
for i in range(n):
	if t%x[i] <= e or x[i] - t%x[i] <= e:
		print i+1
		break
else:
	print -1