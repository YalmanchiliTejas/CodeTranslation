n = int(input())
S = [input() for i in range(n)]

check = [[0] * 26 for i in range(n)]
for i in range(n):
    for j in S[i]:
        check[i][ord(j)-ord('a')] += 1

ans = ''
for i in range(26):
    num = 500
    for j in range(n):
        num = min(num, check[j][i])
    ans += chr(i + ord('a')) * num

print(ans)