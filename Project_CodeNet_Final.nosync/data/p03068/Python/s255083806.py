N = int(input())
S = input()
K = int(input())

ans = []
moji = S[K-1]

for i in range(len(S)):
    if S[i] == moji:
        ans += S[i]
    else:
        ans += '*'

ans = ','.join(ans)
ans = ans.replace(',', '')

print(ans)