N = int(input())
H = list(map(int, input().split()))
cnt = 1
min = H[0]

for i in range(1,N):
	if H[i] >= min:
		cnt += 1
		min = H[i]
print(cnt)