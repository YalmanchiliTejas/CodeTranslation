N = int(input())
S = input()
K = int(input())
char = S[K-1]
ans = ''

for i in range(N):
    if S[i] == char:
        ans += S[i]
    else:
        ans += "*"

print(ans)