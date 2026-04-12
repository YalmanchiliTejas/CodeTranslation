# -*- coding: utf-8 -*-

import sys

'''

'''

def func():
    '''

    '''

    m = int(raw_input())
    
    for num in range(m):
        init = int(raw_input())
        years = int(raw_input())
        n = int(raw_input())

        answer = 0
        for ope_num in range(n):
            operation, interest, fee = map(float, raw_input().split())
            operation = int(operation)
            if operation == 0:
                a = init
                b = 0
                for year in range(years):
                    b += (int)(a * interest)
                    a -= fee
                    #print a, b
                res = int(a + b)
            if operation == 1:
                a = init
                for year in range(years):
                    a = (int)(a * (1.0 + interest))
                    a -= fee
                    #print a
                res = int(a)

            if answer < res:
                answer = res

        print answer

    return None

if __name__ == '__main__':
    func()
    