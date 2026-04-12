N = int(input())
S = input()
K = int(input())

K -= 1

ans = ['*'] * N

for i in range(0, N):
	if S[i] == S[K]:
		ans[i] = S[K]

T = ''.join(ans)

print(T)