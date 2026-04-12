N = int(input())
S = input()
K = int(input())

ans =""
char = S[K-1]
for i in range(N):
    if S[i] != char:
        ans += "*"
    else:
        ans += S[i]
print(ans)

