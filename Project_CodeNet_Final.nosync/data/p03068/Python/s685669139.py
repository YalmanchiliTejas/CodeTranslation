N = int(input())
s = input()
K = int(input())

ans = ''
for ss in s:
    if ss == s[K - 1]:
        ans += s[K - 1]
    else:
        ans += '*'
print(ans)
