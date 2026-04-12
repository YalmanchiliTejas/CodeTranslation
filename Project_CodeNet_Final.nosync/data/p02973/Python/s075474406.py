def e_sequence_decomposing(N, A):
    # 求める解は、「与えられた数列の、単調非増加部分列の長さの最大値」
    # なので、「与えられた数列を逆にした数列の、単調非減少部分列の長さの最大値」
    # を求める。これは Longest Increasing Subsequence の考え方を援用できる。
    import bisect

    # lnds[k]: ある要素まで見たときにk+1個の非減少部分列が作れるもののうち、
    # 最も要素の値が小さいもの
    lnds = []  # Longest Non-Decreasing Subsequence

    for a in A[::-1]:
        idx = bisect.bisect_right(lnds, a)
        if idx == len(lnds):
            lnds.append(a)
        else:
            lnds[idx] = a
    return len(lnds)

N = int(input())
A = [int(input()) for _ in range(N)]
print(e_sequence_decomposing(N, A))