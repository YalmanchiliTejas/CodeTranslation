#dt = {} for i in x: dt[i] = dt.get(i,0)+1
import sys;input = sys.stdin.readline
inp,ip = lambda :int(input()),lambda :[int(w) for w in input().split()]

M = 10**9+7
n = inp()
x = ip()

sm = sum(x)
sq = sm*sm
ans = 0
for i in x: ans += i*i
ans = (sq-ans)//2
print(ans%M)