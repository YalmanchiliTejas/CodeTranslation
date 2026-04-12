N = int(input())
S = input()
K = int(input())

c = S[K-1]
for i in range(len(S)):
    if S[i] != c:
        S = S[:i] + '*' + S[i+1:]
print(S)