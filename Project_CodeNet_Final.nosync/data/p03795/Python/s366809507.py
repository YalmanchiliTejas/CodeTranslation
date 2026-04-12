N = int(input())

if N < 15:
	answer = 800 * N
elif N >=15: 
	answer = (800 * N) - 200 * (N//15)

print(answer)