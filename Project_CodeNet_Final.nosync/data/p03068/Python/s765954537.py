N = int(input())
S = input()
K = int(input())

char = S[K-1]
ans = ""
for i in S:
    if i != char:
        ans += "*"
    else:
        ans += char
print(ans)