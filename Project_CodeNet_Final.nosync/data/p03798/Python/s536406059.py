N = int(raw_input())
s = raw_input()
def opp(a):
	return 'S' if a == 'W' else 'W'
def det(a0, a1):
	ap = a0
	ac = a1
	ans = a0

	for c in s[1:]+s[:2]:
		ans += ac
		if (c == 'o' and ac == 'S') or (c == 'x' and ac == 'W'):
			an = ap
		else:
			an = opp(ap)
		ap = ac
		ac = an
	if ans[-2:] == ans[:2]:
		return ans[:-2]
	else:
		return None
for pref in ["SS", "SW", "WW", "WS"]:
	ans = det(pref[0], pref[1])
	if ans:
		break
print -1 if not ans else ans