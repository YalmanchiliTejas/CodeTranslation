# import math
# import itertools
# from collections import deque
# from collections import defaultdict
# import heapq
# import sys
# import bisect
# import numpy as np
# from scipy.special import comb


INF = 1001001001001


def main():

    A, B, C, X, Y = map(int, input().split())
    ab_max = 2 * max(X, Y)

    ans = INF
    for i in range(0, ab_max + 1, 2):
        a_num = max(0, X - i // 2)
        b_num = max(0, Y - i // 2)
        price = A * a_num + B * b_num + C * i
        #print(a_num, b_num, i, price)
        ans = min(ans, price)

    print(ans)


if __name__ == '__main__':
    main()
