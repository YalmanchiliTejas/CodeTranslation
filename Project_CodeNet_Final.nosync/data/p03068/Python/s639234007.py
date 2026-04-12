N = int(input())
S = input()
K = int(input())

a = S[K-1]
S_ = [i for i in S]
for i in range(N):
    if S[i] != a:
        S_[i] = "*"
print(*S_, sep="")