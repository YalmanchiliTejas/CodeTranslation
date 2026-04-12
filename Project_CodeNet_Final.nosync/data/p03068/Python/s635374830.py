n = int(input())
S = input()
k = int(input())

c = S[k-1]
ans = str()
for s in S:
    if s == c:
        ans += s
    else:
        ans += "*"

print(ans)