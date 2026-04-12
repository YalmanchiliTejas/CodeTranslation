n = int(input())
h = [int(i) for i in input().split()]

ans = 0
for i in range(n):
	flag = True
	for j in range(i):
		if h[i] < h[j]:flag=False
	ans+=flag
print(ans)