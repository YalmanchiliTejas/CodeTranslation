N = int(input())

base = {chr(i): 0 for i in range(ord('a'), ord('a') + 26)}
S = input()
for s in S:
    base[s] += 1

for i in range(N - 1):
    cnt = {chr(i): 0 for i in range(ord('a'), ord('a') + 26)}
    S = input()
    for s in S:
        cnt[s] += 1
    for c in range(ord('a'), ord('a') + 26):
        base[chr(c)] = min(base[chr(c)], cnt[chr(c)])

base = [[c, v] for c, v in base.items() if v > 0]
base.sort()
ans = ""
for c, v in base:
    ans += c * v
print(ans)
