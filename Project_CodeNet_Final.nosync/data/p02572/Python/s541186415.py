def main():
	n = int(input())
	h = list(map(int,input().split()))

	sum_h = sum(h)%(10**9 + 7)
	ans = 0
	for i in h:
		i = i%(10**9 + 7)
		sum_h -= i
		ans += i*sum_h

	print(ans%(10**9 + 7))
	

	

if __name__ == '__main__':
	main()