n = int(input())
S = []
cnt = [100]*26
for i in range(n):
    S.append(input())
base = "abcdefghijklmnopqrstuvwxyz"
for i in range(26):
    for j in range(n):
        x = S[j].count(base[i])
        cnt[i] = min(x,cnt[i])
res = ""
for i in range(26):
    res += base[i]*cnt[i]
print(res)