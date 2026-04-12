N = int(input())
S = input()
K = int(input())
c = S[K-1]
ans = ''
for ch in S:
    if ch != c:
        ans = ans + '*'
    else:
        ans = ans + ch
print(ans)