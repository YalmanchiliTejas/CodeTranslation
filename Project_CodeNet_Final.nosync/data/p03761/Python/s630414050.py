alp = list("abcdefghijklmnopqrstuvwxyz")
n = int(input())
S = []
ans = ""
for i in range(n):
    S.append(input())
for i in alp:
    p = 10 ** 9
    for i2 in range(n):
        p = min(S[i2].count(i),p)
    ans += i * p
print(ans)
