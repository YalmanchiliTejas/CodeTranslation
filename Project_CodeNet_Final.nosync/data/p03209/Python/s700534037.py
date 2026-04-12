# ABC115D - Christmas
def burger(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    if x <= 1 + B[n - 1]:
        return burger(n - 1, x - 1)
    return burger(n - 1, x - 2 - B[n - 1]) + P[n - 1] + 1


def main():
    global B, P
    N, X = tuple(map(int, input().split()))
    B, P = [1], [1]  # burger, patty
    for i in range(N):
        B += [B[i] * 2 + 3]
        P += [P[i] * 2 + 1]
    ans = burger(N, X)
    print(ans)


if __name__ == "__main__":
    main()