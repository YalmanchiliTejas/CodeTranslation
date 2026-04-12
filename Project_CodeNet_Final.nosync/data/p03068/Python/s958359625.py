N = int(input())
S = str(input())
K = int(input())

target = S[K-1]

ans = ''
for i in range(len(S)):
    if S[i] == target:
        ans += ''.join(S[i])
    else:
        ans += ''.join('*')

print(ans)
