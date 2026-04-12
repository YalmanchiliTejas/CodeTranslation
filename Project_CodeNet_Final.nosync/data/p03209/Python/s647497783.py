N, X = map(int, input().split())

cntP = [0]*(N+1)
cntP[0] = 1
for i in range(1, N+1):
    cntP[i] = cntP[i-1] * 2 + 1

layer = 1
for _ in range(N):
    layer = layer * 2 + 3

def calc(n, i, layer):
    if i == 0:
        return 0
    
    if n == 1:
        return "BPPPB"[:i].count("P")
    else:
        if i == layer // 2 + 1:
            return cntP[n-1] + 1
        elif i > layer // 2 + 1:
            return cntP[n-1] + 1 + calc(n-1, i - (layer // 2 + 1), (layer-3) // 2)
        elif i < layer // 2 + 1:
            return calc(n-1, i-1, (layer-3) // 2)

ans = calc(N, X, layer)
print(ans)
