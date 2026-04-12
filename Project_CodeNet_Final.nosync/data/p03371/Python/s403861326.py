A, B, C, X, Y= map(int, input().split())

ans = 10 ** 15
for i in range(max(X, Y) * 2 + 1):
    N = C * i * 2 + max(0, X - i) * A + max(0, Y - i) * B
    ans = min(ans, N)
print(ans)  