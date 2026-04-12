N, X = map(int, input().split())
pcnt = [0] * (N+1)
fcnt = [0] * (N+1)
pcnt[0] = fcnt[0] = 1
for i in range(N):
	pcnt[i+1] = pcnt[i]*2+1
	fcnt[i+1] = fcnt[i]*2+3

def func(l=N, x=X):
	if (l == 0):
		if (x >= 1):
			return 1
		else:
			return 0
	if (x < fcnt[l-1]+2):
		return func(l-1, x-1)
	else:
		return pcnt[l-1]+1+func(l-1, x-fcnt[l-1]-2)

print(func())
