import collections,sys,string
n = int(sys.stdin.readline())
a = [collections.defaultdict(int) for _ in range(n)]
for i in range(n):
	ai = a[i]
	s = input()
	for c in s:
		ai[c] += 1
r = ''
for c in string.ascii_lowercase:
	cc = min(t[c] for t in a)
	r += c * cc
print(r)