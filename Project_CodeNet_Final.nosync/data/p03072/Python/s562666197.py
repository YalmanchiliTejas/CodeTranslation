N = int(input())
H = list(map(int,input().split()))

L = [0] * N
L[0] = H[0]

count = 1
for i in range(1,N):
	L[i] = max(L[i-1],H[i])
	if L[i-1] <= H[i]:
		count += 1

print (count)