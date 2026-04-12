N = int(input())
S = input()
K = int(input())

ans = list(S)
c = S[K-1]

for i in range(N):
    if S[i] != c:
        ans[i] = '*'
    

print(''.join(ans))