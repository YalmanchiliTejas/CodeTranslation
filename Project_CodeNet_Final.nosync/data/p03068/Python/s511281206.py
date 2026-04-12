N = int(input())
S = input()
K = int(input())

s = S[K-1]
ans = ""
for a in S :
    if a == s :
        ans += s
    else :
        ans += "*"
print(ans)