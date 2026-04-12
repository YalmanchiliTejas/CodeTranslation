n = int(input())
s = [input() for _ in range(n)]
l = "abcdefghijklmnopqrstuvwxyz"
ans = ""
for i in l:
    tnp = 100
    for j in range(n):
        tnp = min(tnp,s[j].count(i))
    ans += i*tnp
print(ans)
    