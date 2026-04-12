A, B, C, X, Y = map(int, input().split())
res = float('Inf')
for Z in range(10**5+1):
    total = 2*Z*C + max(0, X - Z)*A + max(0, Y - Z)*B
    if res > total:
        res = total
print(res)