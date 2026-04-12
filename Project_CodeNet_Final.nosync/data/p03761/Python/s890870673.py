n = int(input())
s = [input() for _ in range(n)]
abc = list("abcdefghijklmnopqrstuvwxyz")
ans = ""
for i in range(26):
	cnt = 10*8
	for j in range(n):
		cnt = min(cnt, s[j].count(abc[i]))
	ans += abc[i]*cnt
print(ans)