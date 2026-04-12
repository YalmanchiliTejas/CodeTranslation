def main():
    N = int(input())
    S = list(input())
    K = int(input())

    k_str = S[K-1]
    for i in range(len(S)):
        if S[i] != k_str:
            S[i] = '*'

    print(''.join(S))


if __name__ == '__main__':
    main()