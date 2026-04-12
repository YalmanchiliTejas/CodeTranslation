N = int(input())
S = str(input())
K = int(input())

k_s = S[K-1]
ans = ''
for s in S:
    if s == k_s:
        ans += k_s
    else:
        ans+='*'
print(ans)
