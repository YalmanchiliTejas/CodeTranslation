N = int(input())
S = input()
K = int(input())
moji = S[K-1]
for i in range(len(S)):
    if S[i] != moji:
        S = S.replace(S[i],"*")
print(S)