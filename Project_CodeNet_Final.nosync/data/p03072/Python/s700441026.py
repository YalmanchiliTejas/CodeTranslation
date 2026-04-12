n = int(input())
h = [int(n) for n in input().split()]

ans = 1
for i in range(1, n):
	flag = True
	for j in range(0, i):
		if (h[j]>h[i]):
			flag = False
	if (flag==True):
		ans += 1
print(ans)