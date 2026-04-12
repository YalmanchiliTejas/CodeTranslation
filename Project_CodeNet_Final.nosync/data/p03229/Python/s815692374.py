def main():
    N, *A = map(int, open(0).read().split())
    A.sort()
    if N % 2 == 0:
        s, l = A[:N//2], A[N//2:]
        ans = 2*(sum(l) - sum(s))
        ans += s[-1] - l[0]
        print(ans)
        return

    sep1 = (N + 1)//2
    s1, l1 = A[:sep1], A[sep1:]
    # print(s1, l1)
    ans1 = 2*(sum(l1) - sum(s1))
    ans1 += s1[-1] + s1[-2]

    sep2 = sep1 - 1
    s2, l2 = A[:sep2], A[sep2:]
    # print(s2, l2)
    ans2 = 2*(sum(l2) - sum(s2))
    ans2 -= l2[0] + l2[1]

    print(max(ans1, ans2))

if __name__ == '__main__':
    main()
