n, x, m = map(int, input().split())
g = x * 1
ans = x
arr = []
res = set([])
loop = (0, 0)
k = 0
for i in range(m + 1):
	tmp = x ** 2 % m
	if tmp in res:
		loop = (i, tmp)
		break
	res.add(tmp)
	arr.append(tmp)
	ans += tmp
	x = tmp

for i, y in enumerate(arr):
	if y == loop[1]:
		k = i
		break

ini = g + sum(arr[:k])
mul = ans - ini
t, v = divmod(n - k - 1, loop[0] - k)
print(ini + mul * t + sum(arr[k:k + v]))
