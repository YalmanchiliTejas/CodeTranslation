n = int(input())
d = {}
for i in range(n):
    s = input()
    for j in range(len(s)):
        if s[j] not in d:
            d[s[j]] = [0] * n
            d[s[j]][i] += 1
        else:
            d[s[j]][i] += 1
ans = ""
for k, v in d.items():
    ans += k * min(v)
print("" .join(sorted(ans)))
