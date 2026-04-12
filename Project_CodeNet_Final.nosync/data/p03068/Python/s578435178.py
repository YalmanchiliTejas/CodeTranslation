N = int(input())
S = input()
K = int(input())
ans = ""
for i in range(N):
    ans += "*" if S[i] != S[K-1] else S[i]
print(ans)
