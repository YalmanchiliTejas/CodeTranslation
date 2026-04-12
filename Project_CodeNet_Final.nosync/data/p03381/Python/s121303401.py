def inpl(): return list(map(int, input().split()))

N = int(input())
ns = inpl()
nss = sorted(ns)
c1 = nss[int(N/2)-1]
c2 = nss[int(N/2)]
for i in range(N):
	if ns[i] <= c1:
		print(c2)
	else:
		print(c1)