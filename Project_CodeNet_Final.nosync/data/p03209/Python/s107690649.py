N, X = map(int, input().split())
hight, paty = [0]*51, [0]*51
hight[0] = 1
paty[0] = 1

for i in range(1, 51):
	hight[i] = 2*hight[i-1] + 3
	paty[i] = 2*paty[i-1] + 1

def f(n, x):
	if x == 0: return 0
	elif n == 0: return 1

	elif x <= (hight[n-1]+1):
		return f(n-1, x-1)
	else:
		return paty[n-1] + 1 + f(n-1, x-hight[n-1]-2)

print(f(N, X))