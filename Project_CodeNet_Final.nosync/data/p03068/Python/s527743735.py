N = int(input())
S = input()
K = int(input())
a = S[K-1]
ans = ''
for x in S:
    if x == a:
        ans += a
    else:
        ans += '*'
print(ans)