# ABC154e


def main():
    import sys
    import math
    input = sys.stdin.readline
    sys.setrecursionlimit(10 ** 6)
    # 再帰関数を使わない限りPypyで出すこと

    n = int(input())
    ns = str(n)
    k = int(input())
    keta = len(ns)

    if keta < k:
        print(0)
        exit(0)

        # dp[i+1][smaller][j]=i桁目までで、未満フラグをsmaller、0の個数j
    dp = [[[0]*(keta+1) for i in range(2)]
          for j in range(keta + 1)]

    dp[0][0][0] = 1

    for i in range(keta):
        for smaller in range(2):
            for j in range(i+1):
                for x in range(10 if smaller == 1 else int(ns[i])+1):
                    # if i == 0 and x == 0:
                    #    continue
                    dp[i + 1][1 if smaller == 1 or x < int(ns[i])
                              else 0][j if x != 0 else j+1] += dp[i][smaller][j]
    # print(dp)
    # print(dp[keta][0][keta-k])
    #print(dp[keta][1][keta - k])
    print(dp[keta][0][keta-k]+dp[keta][1][keta - k])


if __name__ == '__main__':
    main()
