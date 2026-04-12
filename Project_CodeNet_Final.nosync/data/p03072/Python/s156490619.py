''' بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ '''
#codeforces1197
gi = lambda : list(map(int,input().strip().split()))
n, = gi()
l = gi()
ans = 0
m = -1
for e in l:
	if e >= m:
		m = e
		ans += 1
print(ans)