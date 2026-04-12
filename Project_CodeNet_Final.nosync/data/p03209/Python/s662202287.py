n, x = map(int, input().split())

burger = [1]*(n+1)
patty = [1]*(n+1)

stopped = 0
for i in range(1,n):
	burger[i] = 2*burger[i-1]+3
	patty[i] = 2*patty[i-1]+1
	
def solve(n, x):
	if n == 0:
		if x == 0:
			return 0
		else:
			return 1
	elif n == 1:
		if x == 0:
			return 0
		elif x == 1:
			return 0
		elif x == 2:
			return 1
		elif x == 3:
			return 2
		elif x == 4:
			return 3
		else:
			return 3
	elif x == 0:
		return 0
	elif x == burger[n]:
		return patty[n]
	elif x == burger[n-1]+1:
		return patty[n-1]
	elif x == burger[n-1]+2:
		return patty[n-1]+1
	elif x < burger[n-1]+2:
		return solve(n-1, x-1)
	elif x > burger[n-1]+2:
		return solve(n-1, x-burger[n-1]-2)+patty[n-1]+1

print(solve(n, x))