N = int(input())
S = input()
K = int(input())
s = [S[i:i+1] for i in range(N)]
st = s[K - 1]
ans = ''
for word in s:
    if word == st:
        ans += st
    else:
        ans += '*'
print(ans)
