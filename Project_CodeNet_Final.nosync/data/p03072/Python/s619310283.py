N = int(input())

H = list(map(int , input().split()))

count = 1

for n in range(1 , N):
	for j in range(n):
		B = True
		if H[j] > H[n]:
			B = False
			break
	if B == True:
		count += 1

print(count)

