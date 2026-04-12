A, B, C, X, Y = list(map(int, input().split()))

result = float('inf')
for i in range(0, max(X, Y)+1):
    tmp = C*2*i + max(0, X-i) * A + max(0, Y-i) * B
    if tmp < result:
        result = tmp
print(result)
