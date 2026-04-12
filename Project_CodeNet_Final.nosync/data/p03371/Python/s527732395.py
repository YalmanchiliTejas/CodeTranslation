A, B, C, X, Y = map(int, input().split())

l = list()
for i in range(max(X, Y)+1):
    cst = 2*C*i + max(0, X-i)*A + max(0, Y-i)*B
    l.append(cst)

print(min(l))