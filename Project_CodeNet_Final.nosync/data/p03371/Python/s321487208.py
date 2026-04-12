A, B, C, X, Y = map(int, input().split())
# ナップザック問題、にするまでもない。
for i in range(max(X,Y)+1):
    cost = i * 2*C + max(X-i, 0)*A + max(Y-i, 0) *B
    if i ==0:
        res = cost
    else:
        res = min(res, cost)
print(res)