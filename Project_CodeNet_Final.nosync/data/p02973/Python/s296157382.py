# ABC134E - Sequence Decomposing
def longest_subsequence(A: "Array[int]", equals: bool, increasing: bool) -> int:
    from bisect import bisect_left, bisect_right

    bs = bisect_right if equals else bisect_left
    compare = (lambda x, y: x >= y) if equals else (lambda x, y: x > y)
    if not increasing:
        A = A[::-1]
    
    dp = [A[0]]  # dp := length of LIS (dp table itself is not LIS)
    for i in A[1:]:
        if compare(i, dp[-1]):
            dp.append(i)
        else:
            dp[bs(dp, i)] = i
    return len(dp)


def main():
    N, *A = map(int, open(0))
    ans = longest_subsequence(A, equals=1, increasing=0)
    print(ans)


if __name__ == "__main__":
    main()