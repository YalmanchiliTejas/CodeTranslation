N = input()
S = input()
K = int(input())-1

ans = ''
for s in S:
    if s == S[K]:
        ans += s
    else:
        ans += '*'
print(ans)