n, x = map(int, input().split())

burger = [1]*(n+1)
patty = [1]*(n+1)

stopped = 0
for i in range(1,n+1):
	burger[i] = 2*burger[i-1]+3
	patty[i] = 2*patty[i-1]+1
	
def solve(n, x):
	if x == 0:
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