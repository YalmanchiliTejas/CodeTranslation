N = int(input())
Xs = list(map(int, input().split()))

M1, M2 = sorted(Xs)[N // 2 - 1: N // 2 + 1]

for X in Xs:
    if X < M2:
        print(M2)
    else:
        print(M1)
