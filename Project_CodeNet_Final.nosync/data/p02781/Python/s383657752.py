def solve(i, k, lesser, zero):
	global s, dp

	if k < 0:
		return 0

	if i == len(s):
		return 1 if k == 0 and not zero else 0

	if dp[i][k][lesser][zero] != -1:
		return dp[i][k][lesser][zero]

	if lesser:
		dp[i][k][lesser][zero] = solve(i + 1, k, True, zero)

		for d in range(1, 10):
			dp[i][k][lesser][zero] += solve(i + 1, k - 1, True, False)
	else:
		dp[i][k][lesser][zero] = solve(i + 1, k, 0 < s[i], zero)
		
		for d in range(1, s[i] + 1):
			dp[i][k][lesser][zero] += solve(i + 1, k - 1, d < s[i], False)

	return dp[i][k][lesser][zero]

def main():
	global s, dp

	s = list(input())
	k = int(input())

	for i in range(len(s)):
		s[i] = ord(s[i]) - ord('0')

	dp = [[[[-1, -1], [-1, -1]] for j in range(k + 1)] for i in range(len(s) + 1)]

	print(solve(0, k, False, True))

if __name__ == "__main__":
	main()