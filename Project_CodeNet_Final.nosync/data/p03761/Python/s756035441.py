def main():
    N = int(input())
    S = []
    for i in range(N):
        s = input()
        S.append(s)

    a = []
    st = set(S[0])

    for c in list(st):
        cnt = 10 ** 9
        for s in S:
            cnt = min(cnt, s.count(c))
        for i in range(cnt):
            a.append(c)
            
    ans = sorted(a)
    print("".join(ans))


if __name__ == "__main__":
    main()