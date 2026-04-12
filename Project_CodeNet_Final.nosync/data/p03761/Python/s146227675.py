n = int(input())
S=[input() for _ in range(n)]
ans = ''
for i in range(97, 97+26):
    memo = [0]*ｎ
    for j in range(n):
        memo[j] = S[j].count(chr(i))
    ans += min(memo)*chr(i)

print(ans)