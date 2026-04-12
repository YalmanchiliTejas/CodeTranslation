import bisect


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)][::-1]
    ans = [A[0], ]
    bright = bisect.bisect_right
    L = 1
    for i, a in enumerate(A):
        if i == 0:
            continue
        index = bright(ans, a)
        if index == L:
            ans.append(a)
            L += 1
        else:
            ans[index] = a
    print(L)


if __name__ == "__main__":
    main()
