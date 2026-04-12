# Great Ocean View

N = int(input())
H = list(map(int, input().split()))

cnt = 1
top = H[0]

for i in range(1, N):
	if H[i] >= top:
		cnt += 1
		top = H[i]
		
print(cnt)