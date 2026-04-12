def main():
    import sys
    import bisect

    read = sys.stdin.buffer.read
    bisect_right = bisect.bisect_right

    N, *A = map(int, read().split())

    dp = [A[-1]]
    for a in reversed(A[:-1]):
        if a >= dp[-1]:
            dp.append(a)
        else:
            dp[bisect_right(dp, a)] = a

    print(len(dp))
    return


if __name__ == '__main__':
    main()
