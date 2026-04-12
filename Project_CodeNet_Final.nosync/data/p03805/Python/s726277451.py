N, M = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(M)]

c = 0
rel = {}

for n in range(1, N + 1):
	rel[n] = []

for a, b in AB:
	rel[a] += [b]
	rel[b] += [a]

def trase(r):
	global c
	#print(r)
	if N == len(r):
		c += 1
		return
	for n in rel[r[-1]]:
		if n in r:
			continue
		trase(r + [n])

for n in rel[1]:
	trase([1] + [n])

print(c)
