def main():
    N = int(input())
    S = input()
    K = int(input())
    unchange = S[K-1]
    for i in range(N):
        if S[i] == unchange:
            pass
        else:
            S = S.replace(S[i], '*')
    print(S)


if __name__ == '__main__':
    main()
