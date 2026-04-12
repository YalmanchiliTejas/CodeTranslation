N = int(input())
S = list(str(input()))
K = int(input())

ans = ''
st = S[K-1]
for s in S:
    if s == st:
        ans += s
    else:
        ans += "*"
print(ans)