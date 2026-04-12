import itertools

N, M = list(map(int, input().split()))
L = [[] for i in range(N)]

for i in range(M):
	a, b = list(map(int, input().split()))
	L[a - 1].append(b - 1)
	L[b - 1].append(a - 1)

X = [i for i in range(1, N)]

ans = 0
for s in itertools.permutations(X, N - 1):
	judge = "Yes"
	x = 0
	for i in s:
		if L[i].count(x) == 1:
			pass
			x = i
		else:
			judge = "No"
			break
	if judge == "Yes":
		ans += 1

print(ans)