N = int(input())
H = list(map(int, input().split()))

count = 0

High = H[0]

for i in range(N):
	if H[i] >= High:
		count += 1
		High = H[i]
		

print(count)
