N = int(input())
S = input()
K = int(input())

x = S[K-1]

for i in range(len(S)):
    if S[i] != x:
        S = S.replace(S[i],'*')
print(S)