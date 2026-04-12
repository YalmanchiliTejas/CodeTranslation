N = int(input())
S = input()

# 0: S, 1: Wとする
X = ['S', 'W']
for P in [[0, 0], [0, 1], [1, 0], [1, 1]]:
    for i, s in enumerate(S[1:], start=1):
        if s == 'o' and P[i] == 0:
            P.append(P[i - 1])

        if s == 'o' and P[i] == 1:
            P.append(P[i - 1] ^ 1)

        if s == 'x' and P[i] == 0:
            P.append(P[i - 1] ^ 1)

        if s == 'x' and P[i] == 1:
            P.append(P[i - 1])

    P = P[:-1]
    # 確認
    for i in range(N):
        if (S[i] == 'o') and (P[i] == 0) and (P[i - 1] != P[(i + 1) % N]):
            break

        if (S[i] == 'o') and (P[i] == 1) and (P[i - 1] == P[(i + 1) % N]):
            break

        if (S[i] == 'x') and (P[i] == 0) and (P[i - 1] == P[(i + 1) % N]):
            break

        if (S[i] == 'x') and (P[i] == 1) and (P[i - 1] != P[(i + 1) % N]):
            break

    else:
        ans = [X[p] for p in P]
        print(''.join(ans))
        exit()

print(-1)
