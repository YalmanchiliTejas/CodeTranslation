A, B, C, X, Y = map(int, input().split())
ans = float("inf")

for i in range(max(X,Y)+1):
    total = A*(X-min(X,i)) + B*(Y-min(Y,i)) + C*2*i

    if ans > total:
        ans = total

print(ans)