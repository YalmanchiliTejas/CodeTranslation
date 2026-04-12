while True:
    n = int(input())
    if n == 0:
        break

    S = []
    for i in range(n):
        S.append(int(input()))

    S.sort()
    S = S[1:n-1]

    print(sum(S) // len(S))

