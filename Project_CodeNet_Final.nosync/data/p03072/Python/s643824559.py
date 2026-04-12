n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
	flag = 0
	for j in range(i):
		if a[j] > a[i]: flag = 1
	ans += 1-flag
print(ans)
