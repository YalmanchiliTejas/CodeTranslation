N = int(input())
H = list(map(int, input().split()))
a = 0
h = 0
for i in range(N):
	if H[i] >= h:
		a += 1
		h = H[i]
print(a)
