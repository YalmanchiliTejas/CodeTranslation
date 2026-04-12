N = int(input())
H = list(map(int,input().split(' ')))


ans = 0
for i in range(N):
	f = True
	for j in range(i):
		if H[i] < H[j]:
			f = False
			break
	if f:
		ans += 1

print(ans)


