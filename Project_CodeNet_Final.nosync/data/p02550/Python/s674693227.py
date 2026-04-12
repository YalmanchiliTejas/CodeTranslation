import sys
n, x, m = map(int, input().split())
mod_cnt = [False for _ in range(m)]
mod_cnt[x] = True
cycle = [x]
while len(cycle) < n and not mod_cnt[(x*x) % m]:
	x = (x*x) % m
	mod_cnt[x] = True
	cycle.append(x)

if len(cycle) == n:
	print(sum(cycle))
	sys.exit()

nxt = (x*x) % m
for i in range(len(cycle)):
	if cycle[i] == nxt:
		head = i
		break

ans = sum(cycle[:head])
cycle = cycle[head:]
period = len(cycle)
n -= head
for i, x in enumerate(cycle):
	if i < n % period:
		ans += (n // period + 1) * x
	else:
		ans += (n // period) * x
print(ans)