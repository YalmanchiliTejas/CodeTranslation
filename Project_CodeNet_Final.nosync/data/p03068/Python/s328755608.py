N = int(input())
S = input()
K = int(input())
KC = S[K-1]
ans = ''
for s in S:
    if s == KC:
        ans += KC
    else:
        ans += '*'
print(ans)