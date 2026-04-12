N = int(input())
H = list(map(int, input().split()))

max_h = -1
sum = 0
for i in range(N):
	if H[i] >= max_h:
		sum += 1
		max_h = max(max_h, H[i])
print(sum)