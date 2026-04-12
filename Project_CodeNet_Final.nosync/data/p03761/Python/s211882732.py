n = int(input())

s = [list(input()) for _ in range(n)]
a = [0 for _ in range(26)]

for i in range(len(s[0])):
    a[ord(s[0][i]) - ord("a")] += 1

for i in range(1, n):
    b = [0 for _ in range(26)]
    for j in range(len(s[i])):
        if a[ord(s[i][j]) - ord("a")] == 0:
            continue
        else:
            b[ord(s[i][j]) - ord("a")] += 1

    for k in range(26):
        a[k] = min(a[k], b[k])

if a.count(0) == 26:
    print()
else:
    ans = "" 
    for i in range(26):
        for j in range(a[i]):
            ans += chr(i + ord("a"))
    print(ans)