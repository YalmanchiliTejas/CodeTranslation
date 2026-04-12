from sys import exit

N = int(input())
S = input()
K = int(input())

s = S[K - 1]

ans = ''

for i in range(N):
    if S[i] != s:
        ans += '*'
    else:
        ans += S[i]

print(ans)
