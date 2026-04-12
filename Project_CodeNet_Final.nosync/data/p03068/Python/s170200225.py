N = int(input())
S = input()
K = int(input())

ans = ""
note = S[K-1]
for s in S:
    if s == note:
        ans += note
    else:
        ans += "*"

print(ans)