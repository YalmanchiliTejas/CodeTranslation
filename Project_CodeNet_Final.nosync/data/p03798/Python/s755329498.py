def check(N, S, ans):
    for i in range(N):
        if (ans[i] == "S") ^ (S[i] == "o"):
            if ans[(i-1) % N] == ans[(i+1) % N]:
                return False
        else:
            if ans[(i-1) % N] != ans[(i+1) % N]:
                return False
    return True


def main():
    N = int(input())
    S = input()
    initials = ["SS", "SW", "WS", "WW"]
    for init in initials:
        ans = [""] * N
        ans[0] = init[0]
        ans[1] = init[1]
        for i in range(1, N-1):
            if (ans[i] == "S") ^ (S[i] == "o"):
                ans[i+1] = "W" if ans[i-1] == "S" else "S"
            else:
                ans[i+1] = ans[i-1]
        if check(N, S, ans):
            print("".join(ans))
            return
    print(-1)


if __name__ == "__main__":
    main()
