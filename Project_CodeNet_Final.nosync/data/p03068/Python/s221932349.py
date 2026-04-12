N = int(input())
S = input()
K = int(input())

ans = ''
for c in S:
    ans += (c if c==S[K-1] else '*')
print(ans)