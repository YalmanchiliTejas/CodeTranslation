N = int(input())
S = input()
K = int(input())

ans = ""
target = S[K-1]
for s in S:
    if s == target:
        ans += target
    else:
        ans += "*"
print(ans)