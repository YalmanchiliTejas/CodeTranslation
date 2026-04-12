def func(N, X):
	global l, p

	if l[N] == X:
		return p[N]
	
	if X == 1:
		return 0
	temp = 1 + l[N - 1]
	s = 0
	if X <= temp:
		return func(N - 1, X - 1)
	temp += 1
	if X == temp:
		return p[N - 1] + 1
	temp += l[N - 1]
	if X <= temp:
		return func(N - 1, X - 2 - l[N - 1]) + p[N - 1] + 1
	return 2 * p[N - 1] + 1
	
		
N, X = map(int, input().split())

l = [0] * (N + 1)
p = [0] * (N + 1)

l[0] = 1
p[0] = 1

for i in range(1, N + 1):
	l[i] = 3 + l[i - 1] * 2
	p[i] = 1 + p[i - 1] * 2

ans = func(N, X)

print(ans)