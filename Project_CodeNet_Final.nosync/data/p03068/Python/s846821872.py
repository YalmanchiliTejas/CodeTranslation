def main():
    N = int(input())
    S = list(input())
    K = int(input())

    t = S[K-1]

    for i in range(N):
        if S[i] != t:
            S[i] = '*'

    print(''.join(S))


main()

