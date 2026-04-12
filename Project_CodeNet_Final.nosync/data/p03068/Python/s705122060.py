N = int(input())
S = input()
K = int(input())
t = S[K-1]
ans = ''
for s in S:
    ans += '*' if s!=t else s

print(ans)