N = int(input())
S = input()
K = int(input())

word = S[K-1:K]
S_new = ""

for i in range(N):
    if S[i:i+1] == word:
        S_new += word
    else:
        S_new += "*"
        
print(S_new)