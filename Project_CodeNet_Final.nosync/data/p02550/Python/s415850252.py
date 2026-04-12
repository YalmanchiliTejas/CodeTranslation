def main():
    N, X, M = map(int, input().split())
    a = X
    r = a
    i = 1
    S = {X: (0, 0)}
    ns = True
    while i < N:
        an = (a * a) % M
        if an == 0:
            break
        if ns and an in S:
            l = S[a][1] - S[an][1] + 1
            skip = (N - i - 1) // l
            r += (r - S[an][0]) * skip
            i += l * skip
            ns = False
        if i >= N:
            break
        a = an
        S[a] = (r, i)
        r += a
        i += 1

    return r

# print("Yes" if main() else "No")
print(main())
