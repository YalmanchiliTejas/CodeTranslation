N = int(input())
S = input()
K = int(input())
res = ""
a = S[K - 1]
for i in range(N):
    if S[i] != a:
        res += "*"
    else:
        res += S[i]
print(res)