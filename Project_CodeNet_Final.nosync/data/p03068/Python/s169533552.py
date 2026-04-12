input()
S = input()
K = int(input())

ans = ''
for c in S:
    if c != S[K-1]:
        ans += '*'
    else:
        ans += c

print(ans)
