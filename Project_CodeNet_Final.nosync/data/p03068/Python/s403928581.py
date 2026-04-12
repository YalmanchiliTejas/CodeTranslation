N = int(input())
S = input()
K = int(input())
word = S[K-1]
for i in range(N):
    if S[i] == word:
        a = 1
    else:
        S = S.replace(S[i],"*")
#print(word)
print(S)