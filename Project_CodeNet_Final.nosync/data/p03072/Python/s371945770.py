n = int(input())
h = list(map(int, input().split()))

cnt = 1
for i in range(1, n):
	now = h[i]
	jud = 0
	for j in range(i):
		if now < h[j]:
			jud = 1
			break
	if jud == 0:
		cnt += 1

print(cnt)
