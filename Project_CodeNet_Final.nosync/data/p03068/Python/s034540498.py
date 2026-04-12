N = int(input())
S = input()
K = int(input())
a = S[K -1]
ans = ""
for s in S:
    if s == a:
        ans += a
    else:
        ans += "*"
print(ans)