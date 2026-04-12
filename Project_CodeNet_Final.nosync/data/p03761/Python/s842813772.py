N = int(input())
S = []
for i in range(N):
    S.append(list(input()))
    
X = []
for i in range(len(S[0])):
    check=True
    for j in range(1,N):
        if S[0][i] not in S[j]:
            check = False
        else:
            S[j].remove(S[0][i])
    
    if check:
        X.append(S[0][i])

X.sort()
print("".join(X))