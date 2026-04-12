n, x, m = map(int,input().split())
a = x; s = a
k = {a}
memo = [a]
mode = 0
cnt = 1
for i in range(n-1):
	a = (a**2)%m
	cnt += 1
	memo.append(a)
	if a in k:
		mode = 1
		break
	s += a
	k.add(a)
if mode:
	targ = memo.index(a)
	nagasa = cnt-1-targ
	ruisekiwa = [0 for _ in range(nagasa)]
	ruisekiwa[0] = memo[targ]
	for i in range(1, nagasa):
		ruisekiwa[i] = ruisekiwa[i-1] + memo[i+targ]
	t = n - cnt
	s += ruisekiwa[-1]*(t//nagasa) + ruisekiwa[t%nagasa]
print(s)