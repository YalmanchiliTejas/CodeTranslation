N = int(input())
H = list(map(int,input().split()))

ans = 0

for i in range(N):
	judge = True
	for j in range(i):
		if H[j] > H[i]:
			judge = False
	if judge:
		ans += 1
print(ans)



