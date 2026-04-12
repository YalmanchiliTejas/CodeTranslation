n = int(input())

s = [""] *  n
for i in range(n):
    s[i] = input()

ans = ""
for i in range(26):
    cnt = 50
    for j in range(n):
        cnt = min(cnt, s[j].count(chr(ord("a") + i)))
    ans += chr(ord("a") + i) * cnt
print(ans)
