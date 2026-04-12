N = int(input())
S = input()
K = int(input())

target = S[K - 1]
ans = ""
for s in S:
    if s != target:
        ans += "*"
    else:
        ans += target
print(ans)
