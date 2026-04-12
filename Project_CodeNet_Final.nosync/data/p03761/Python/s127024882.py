import string

n = int(input())
S = [input() for i in range(n)]

D = {}

j = 0
for i in range(ord('a'), ord('z')+1):
    D[chr(i)] = j
    j += 1

LL = [float("inf")] * 26

for i in range(n):
    L = [0] * 26
    for j in range(len(S[i])):
        L[D[S[i][j]]] += 1
    for j in range(26):
        LL[j] = min(LL[j], L[j])
    #print(LL)

ans = ""
j = 0
for i in range(ord('a'), ord('z')+1):
    ans += chr(i) * LL[j]
    j += 1

print(ans)