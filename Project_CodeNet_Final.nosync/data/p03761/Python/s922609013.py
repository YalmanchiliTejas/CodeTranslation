n = int(input())
G = []
for _ in range(n):
    S = list(input().strip())
    C = {}
    for i in range(len(S)):
        x = S[i]
        if x not in C:
            C[x] = 0
        C[x] += 1
    G.append(C)
A = {}
for i in range(97,123):
    flag = 0
    cmin = 50
    for C in G:
        if chr(i) not in C:
            flag = 1
            break
        cmin = min(cmin,C[chr(i)])
    if flag==0:
        A[chr(i)] = cmin
A = sorted(list(A.items()),key=lambda x:x[0])
x = ""
for y in A:
    a,k = y[0],y[1]
    x += a*k
print(x)