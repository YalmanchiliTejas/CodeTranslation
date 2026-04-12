def main():
    N = int(input())
    S = []
    for i in range(N):
        s = input()
        S.append(s)
    # print(S)

    if N == 1:
        ans = sorted(S[0])
        print("".join(ans))
    else:
        a = []
        st = set(S[0])
        cnt = 10 ** 9
        for c in list(st):
            for s in S:
                cnt = min(cnt, s.count(c))
                # print(c, s, cnt)
            # if cnt > 0:
            for i in range(cnt):
                a.append(c)
            cnt = 10 ** 9
        ans = sorted(a)
        print("".join(ans))


if __name__ == "__main__":
    main()