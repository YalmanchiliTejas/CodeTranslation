n = int(input())
s = [input() for _ in range(n)]
ans = ""
abc = "abcdefghijklmnopqrstuvwxyz"
for i in range(26):
    cnt = s[0].count(abc[i])
    for j in range(1, n):
        if cnt >= s[j].count(abc[i]):
            cnt = s[j].count(abc[i])
    if cnt != 0:
        ans += abc[i]*cnt
print(ans)