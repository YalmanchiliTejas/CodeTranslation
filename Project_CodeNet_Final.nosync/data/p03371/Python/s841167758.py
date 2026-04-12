def smaller(m, n):
	if m < n: return m
	else: return n

A, B, C, X, Y = map(int, raw_input().split())

smallerpizza = smaller(X, Y)
morepizza = X + Y - 2*smallerpizza
neededpizza = ''
if smallerpizza == X: neededpizza = 'B'
else: neededpizza = 'A'

cost1 = A + B
if 2 * C < cost1: cost1 = 2 * C
cost2 = 0
if neededpizza == 'A': cost2 = A
if neededpizza == 'B': cost2 = B
if 2 * C < cost2: cost2 = 2 * C

print cost1 * smallerpizza + cost2 * morepizza