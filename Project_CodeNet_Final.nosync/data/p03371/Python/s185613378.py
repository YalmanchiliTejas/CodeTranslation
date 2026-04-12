def C():
    A, B, C, nA, nB = map(int, input().split())
    minAB = min(nA, nB)
    # 3, 2 --> 1, 0
    ns = [nA - minAB, nB - minAB]
    amounts = [
        A * nA + B * nB,
        minAB * 2 * C + ns[0] * A + ns[1] * B,
        max(nA, nB) * 2 * C
    ]
    return min(amounts)

print(C())
