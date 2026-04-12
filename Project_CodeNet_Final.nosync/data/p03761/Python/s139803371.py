n = int(input())
s = []
for _ in range(n):
    tmp_s = sorted(input())
    s.append("".join(tmp_s))

s.sort(key=len)
ans = ''

for i in range(len(s[0])):
    count = 0
    for j in range(len(s) - 1):
        if s[0][i] in s[j+1]:
            s[j+1] = s[j+1].replace(s[0][i], "", 1)
            count += 1

    if count == len(s) - 1:
        ans += s[0][i]

print(ans)
