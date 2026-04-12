N = int(input())
H = [int(_) for _ in input().split()]

a = 1

if N > 1:
	for i in range(1, N):
		if H[i] >= max(H[:i]):
			a += 1

print(a)