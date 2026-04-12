N = int(input())
H = list(map(int, input().split()))

count = 0
maximum = 0

for i in range(N):
	if H[i] >= maximum:
		maximum = H[i]
		count += 1
			
print(count)


