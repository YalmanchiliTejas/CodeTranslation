N = int(input())
S = input()
K = int(input())
res = ''
for i in range(N):
    if S[i] == S[K - 1]:
        res += S[i]
    else:
        res += '*'
print(res)