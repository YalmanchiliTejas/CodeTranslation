N = int(input())
S = list(input())
K = int(input())
x = S[K - 1]
ans = ""
for i in range(N):
	if S[i] == x:
		ans += x
	else:
		ans += "*"

print(ans)