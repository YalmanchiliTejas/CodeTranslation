N = input()
K = int(input())

a = [0] * (K + 1)
b = [0] * (K + 1)

t = int(N[0])

a = 1
b[0] = 1
b[1] = t - 1

for c in N[1:]:
    t = int(c)
    for i in range(K - 1, -1, -1):
        b[i + 1] += b[i] * 9
    if t != 0:
        if t != 1 and a + 1 <= K:
            b[a + 1] += t - 1
        if a <= K:
            b[a] += 1
        a += 1

if a == K:
    print(b[K] + 1)
else:
    print(b[K])
