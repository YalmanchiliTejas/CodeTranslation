N = int(input())
S = input().rstrip()
K = int(input())

sk = S[K-1]

ans = ''
for s in S:
    if s != sk:
        ans += '*'
    else:
        ans += s

print(ans)