#!/env/usr/python3
N, X = map(int, input().split())
n = 1
n_list = [n]
p = 1
p_list = [p]

for i in range(N):
	n = 2*n + 3
	n_list.append(n)

def p_func(L, X):
	p = 0
	if L == 0 and X == 1:
		p = 1
	elif L >= 1 and X == 1:
		p = 0
	elif X <= n_list[L-1]+1:
		p = p_func(L-1, X-1)
	elif X == n_list[L-1]+2:
		p = p_func(L-1, n_list[L-1]) + 1
	elif X <= 2 * n_list[L-1] + 2:
		p = p_func(L-1, X-n_list[L-1]-2) + p_func(L, n_list[L]-n_list[L-1]-2) + 1
	elif X == 2 * n_list[L-1] + 3:
		p = 2 * p_func(L-1, n_list[L-1]) + 1
	return p

print(p_func(N, X))
