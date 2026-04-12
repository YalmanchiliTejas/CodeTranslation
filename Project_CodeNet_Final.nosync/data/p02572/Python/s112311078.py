# -*- coding: utf-8 -*-
"""
@author: H_Hoshigi
"""
def main():
    N = int(input())
    A_lsit = list(map(int, input().split()))

    A_square_list = [A**2 for A in A_lsit]

    sum_A = sum(A_lsit)
    sum_A_square = sum(A_square_list)

    print( ((sum_A**2 - sum_A_square)// 2) % 1000000007 )

if __name__ == "__main__":
    main()

