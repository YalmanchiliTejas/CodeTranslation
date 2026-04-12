def main():
	n = int(input())
	l = list(map(int, input().split()))
	a = sum(l)
	a *= a
	b = sum([i * i for i in l])
	a = (a - b) // 2
	mod = 10**9 + 7
	print(a % mod)

main()