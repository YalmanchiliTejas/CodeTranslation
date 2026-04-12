N, X = map(int, input().split(' '))
height = [1]

for i in range(N):
	height.append(height[-1]*2 + 3)

def patty(N,X):
	if N==1:
		l = [0,1,2,3,3]
		return l[X-1]
	elif N>=2:
		if X == 1:
			return 0
		elif X <= height[N-1]+1:
			return patty(N-1,X-1)
		elif X == height[N-1]+2:
			return patty(N-1,height[N-1])+1
		elif X == height[N]:
			return patty(N-1,height[N-1])*2+1
		elif X >= height[N-1]+3:
			return patty(N-1,height[N-1])+1+ patty(N-1,X-2-height[N-1])

print(patty(N,X))
