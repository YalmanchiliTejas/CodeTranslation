def main():
	# n,k = map(int,input().split())
	n = int(input())
	# s = str(input())
	a = list(map(int,input().split()))
	# l = [list(map(int, input().split())) for _ in range(n)]
	ans = 1
	for i in range(1,n):
		# print(max(a[:i]))
		if a[i] >= a[0] and a[i] >= a[i-1] and max(a[:i]) <= a[i]:
			ans += 1
	print(ans)



if __name__ == '__main__':
	main()