N = int(input())
A = []
for i in range(N):
	A.append(int(input()))
A.sort()
a, b = [0] * N, [0] * N
c, d = A[:(N + 1) // 2], A[(N + 1) // 2:]
a[0] = c[len(c) - 1]
c.pop()
if N % 2:
	if len(c):
		a[len(a) - 1] = c[len(c) - 1]
		c.pop()
else:
	a[len(a) - 1] = d[0]
	d.pop(0)
e, f = A[:N // 2], A[N // 2:]
b[0] = f[0]
f.pop(0)
if N % 2:
	if len(f):
		b[len(b) - 1] = f[0]
		f.pop(0)
else:
	b[len(b) - 1] = e[len(e) - 1]
	e.pop()
i = 1
while i < N - 1:
	if i % 2:
		a[i] = d[len(d) - 1]
		b[i] = e[len(e) - 1]
		d.pop()
		e.pop()
	else:
		a[i] = c[len(c) - 1]
		b[i] = f[len(f) - 1]
		c.pop()
		f.pop()
	i += 1
g = [0, 0]
i = 1
while i < N:
	g[0] += abs(a[i - 1] - a[i])
	g[1] += abs(b[i - 1] - b[i])
	i += 1
print(max(g[0], g[1]))