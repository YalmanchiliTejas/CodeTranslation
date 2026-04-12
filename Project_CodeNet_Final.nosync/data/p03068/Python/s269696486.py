N = int(input())
S = input()
K = int(input())
str = S[K-1]
for i in range(N):
    if S[i] != str:
        S=S.replace(S[i],'*')
print(S)
