N = int(input())
S = list(input())
K = int(input())
ans = ''
for i in S:
    if i == S[K-1]:
        ans += S[K-1]
    else:
        ans += '*'
print(ans)