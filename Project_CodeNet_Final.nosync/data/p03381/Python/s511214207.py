#!python3

# input
N = int(input())
X = list(map(int, input().split()))


def main():
    W = sorted(X)
    a = N // 2
    for i in range(N):
        if X[i] < W[a]:
            print(W[a])
        else:
            print(W[a - 1])


if __name__ == "__main__":
    main()
