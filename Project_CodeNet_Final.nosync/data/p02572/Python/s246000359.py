# -*- coding: utf-8 -*-
import sys


def main():
    N = int( sys.stdin.readline() )
    A_list = list(map(int, sys.stdin.readline().split()))
    
    cum_sum = 0
    A_cum_sum = []

    for i in range(len(A_list)):
        cum_sum += A_list[i]
        A_cum_sum.append(cum_sum)


    mod = 10**9 + 7
    S = 0

    for i in range(len(A_list)):
        S += A_list[i] * ( A_cum_sum[-1] - A_cum_sum[i] )
        S %= mod
    
    print(S)


if __name__ == "__main__":
    main()
