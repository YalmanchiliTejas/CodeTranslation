def main():
	N = int(input())
	S = input()
	K = int(input())
	non_change = S[K-1]
	ans = ""
	for c in S:
		if c != non_change:
			ans += "*"
		else:
			ans += c
	print(ans)

if __name__ == '__main__':
	main()