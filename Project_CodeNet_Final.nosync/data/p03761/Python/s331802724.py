n = int(input())
s = [input() for i in range(n)]
t = sorted(set(s[0]))
ans = ""
for i in t:
    c = min([s[j].count(i) for j in range(n)])
    ans += i*c
print(ans)