n = int(input())

S = [[0 for i in range(26)] for j in range(n)]

for i in range(n):
    seek = 0
    s = input().rstrip()
    for x in s:
        S[i][ord(x) - 97] += 1

ans = ''
for i in range(26):
    m = 51
    for j in range(n):
        m = min(m, S[j][i])
    ans += chr(i + 97) * m

print(ans)
