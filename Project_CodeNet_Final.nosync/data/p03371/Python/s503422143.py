A, B, C, X, Y = map(int, input().split())
P = []

for i in range(0, max(X, Y)+1):
    if min(X, Y)-i >= 0:
        P.append(A*(X-i) + B*(Y-i) + 2*C*i)
    else:
        if X > Y:
            P.append(A*(X-i) + 2*C*i)
        else:
            P.append(B*(Y-i) + 2*C*i)

print(min(P))
