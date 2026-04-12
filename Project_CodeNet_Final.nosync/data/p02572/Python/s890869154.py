def solve(N, As):
    Ss = [0]
    total = 0
    for a in As:
        Ss.append(Ss[-1] + a)
    for i in range(N - 1):
        total += As[i] * (Ss[-1] - Ss[i + 1])
    ans = total % (10 ** 9 + 7)
    print(ans)


if __name__ == "__main__":
    N = int(input())
    As = list(map(int, input().split()))
    solve(N, As)
