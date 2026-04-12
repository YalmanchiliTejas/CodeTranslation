N = int(input())
S = input()
K = int(input())

letter = S[K-1]

ans = ""
for s in S:
    if s != letter:
        ans += "*"
    else:
        ans += s
print(ans)