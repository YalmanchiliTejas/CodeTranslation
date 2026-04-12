
N = int(input())
S = input()
K = int(input())

target = S[K-1]
ans = ""
for s in S:
    if not s == target:
        ans = ans + "*"
    else:
        ans = ans + s
print(ans)