import sys
n = int(input())
s = [sys.stdin.readline().rstrip() for i in range(n)]
c = [60]*26
ans = []
# a ~ zまでの最小個数を求める
for i in s:
	t = [0]*26
	for j in i:
		t[ord(j)-97] += 1
	for i,j in enumerate(t):
		c[i] = min(j,c[i])
for i,j in enumerate(c):
	ans += chr(i+97)*j
print("".join(ans))