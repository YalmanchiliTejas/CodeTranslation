N = int(input())
H = list(map(int, input().split()))

def hoge(H, n):
	for i in range(n):
		if H[i]>H[n]:
			return 0
	return 1

count = 0
for i in range(N):
	count += hoge(H, i)

print(count)