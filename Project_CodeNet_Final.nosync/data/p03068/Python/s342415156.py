N = int(input())
S = input()
K = int(input())

target = S[K-1]
ans = ""

for i in S:
    if i == target:
        ans += i
    else:
        ans += "*"
print(ans)