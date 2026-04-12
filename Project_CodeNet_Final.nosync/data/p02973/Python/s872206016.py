# ABC134E - Sequence Decomposing
def lis(A: "Array[int]") -> int:
    from bisect import bisect_right

    # dp := length of LIS (dp table itself is not LIS)
    dp = [A[0]]
    for i in A[1:]:
        if i >= dp[-1]:
            dp.append(i)
        else:
            dp[bisect_right(dp, i)] = i
    return len(dp)


def main():
    N, *A = map(int, open(0))
    ans = lis(A[::-1])  # need the length of LDS -> reverse A
    print(ans)


if __name__ == "__main__":
    main()