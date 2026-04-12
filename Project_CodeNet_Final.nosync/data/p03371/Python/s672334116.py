A, B, C, X, Y = map(int, input().split())

ans = A*X + B*Y
for i in range(2, 2*max(X, Y)+1, 2):
    tmp = A*(max(0, X-i//2)) + B*(max(0, Y-i//2)) + C*i
    if tmp < ans:
        ans = tmp

print(ans)