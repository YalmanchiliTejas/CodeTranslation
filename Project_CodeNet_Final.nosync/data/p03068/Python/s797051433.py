N = int(input())
S = input()
K = int(input())

a = S[K-1]
ans = ""
for i in S:
    if i == a:
        ans += i
    else:
        ans += "*"
print(ans)
