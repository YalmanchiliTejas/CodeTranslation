N = int(input())
S = input()
K = int(input())

C = S[K-1]

ans = ""

for i in range(N):
    if S[i] == C:
        ans += C
    else:
        ans += "*"
print(ans)
