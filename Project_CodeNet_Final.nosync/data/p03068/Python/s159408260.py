N = int(input())
S = list(input())
K = int(input())

target = S[K-1]
ans = ""
for s in S:
    ans += s if s == target else "*"
print(ans)
