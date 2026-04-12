n = int(input())
a = [int(i) for i in input().split()]
ans = 0
max = 0
for i in range(n):
	if a[i] >= max:
		ans += 1
		max = a[i]
	else:
		pass
print(ans)