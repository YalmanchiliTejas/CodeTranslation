N = int(input())
S = str(input())
K = int(input())

check = S[K-1]
# print(check)

ans = ''
for s in S:
    if s != check:
        ans += '*'
    else:
        ans += s
print(ans)