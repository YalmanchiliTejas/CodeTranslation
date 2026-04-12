from collections import Counter
N = int(input())
W = [Counter(input()) for k in range(N)]
A = [100000]*26
S = "abcdefghijklmnopqrstuvwxyz"
for e in W:
    for s in S:
        A[ord(s)-97] = min(A[ord(s)-97],e[s])

ans = ""
for k in range(26):
    ans += S[k]*A[k]
print(ans)
