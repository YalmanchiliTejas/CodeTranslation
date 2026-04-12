N = int(input())
S = input()
K = int(input())

c = S[K-1]
ans = ''

for i in range(N):
    if S[i] != c:
        ans += '*'
    else:
        ans += c

print(ans)