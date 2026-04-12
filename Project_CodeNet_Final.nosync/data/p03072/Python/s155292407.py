N = int(input())
H = list(map(int, input().split()))

cn = 1
L = []

for i in range(N):
    if i == 0:
        L.append(H[i])
    else:
        if max(L) <= H[i]:
            cn = cn + 1
            L.append(H[i])

print(cn)