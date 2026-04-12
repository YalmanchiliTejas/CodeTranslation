n = int(input())
S = [input() for _ in range(n)]

f_inf = float("inf")
ans = [f_inf] * 26
for i in range(26):
    subs = 97 + i
    for s in S:
        ans[i] = min(ans[i], s.count(chr(subs)))

for i in range(26):
    for j in range(ans[i]):
        print(chr(97 + i), end="")
