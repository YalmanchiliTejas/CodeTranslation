#B
N = int(input())
S = str(input())
K = int(input())
char = S[K - 1]
ans = ''
for c in S:
    if c == char:
        ans = ans + char
    else:
        ans = ans + '*'
print(ans)
