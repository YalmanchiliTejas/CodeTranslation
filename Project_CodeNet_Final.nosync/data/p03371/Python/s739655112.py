A, B, C, X, Y = map(int, input().split())
minyen = 1000000000
for i in range(0, 2*max(X, Y)+1, 2):
    yen = i * C
    yen += max(0, X - i//2) * A
    yen += max(0, Y - i//2) * B
    minyen = min(minyen, yen)
print(minyen)
