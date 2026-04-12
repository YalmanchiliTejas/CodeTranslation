N = int(input())
H = list(map(int,input().split()))


k = 0
h = []

for i in range(N):
	h.append(H[i])
	if H[i] == max(h):
		k += 1
	else:
		k += 0

print(k)
