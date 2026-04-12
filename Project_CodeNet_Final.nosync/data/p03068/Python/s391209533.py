
def main():
    N = int(input())
    S = input()
    K = int(input())

    S = [S[i] if S[i] == S[K-1] else "*" for i in range(N)]
    print(''.join(S))


if __name__ == "__main__":
    main()