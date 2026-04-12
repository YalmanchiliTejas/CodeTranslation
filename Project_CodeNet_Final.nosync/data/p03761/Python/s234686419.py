n = int(input())

s = []
for i in range(n):
    s.append(input())

ans = ""

for i in range(len(s[0])):
    check = 0
    for j in range(n):
        if not s[0][i] in s[j]:
            check = 1
    if check == 0:
        ans = ans + s[0][i]
        for j in range(1,n):
            re = s[0][i]
            s[j] = s[j].replace(re , '', 1)

ans = ''.join(sorted(ans))
print(ans)