import collections as colle

n = int(input())
Cnt = [colle.Counter(map(ord, list(input()))) for _ in range(n)]
ans = ""
for i in range(97, 123):
    ans += chr(i)*min([Cnt[k][i] for k in range(n)])
print(ans)
