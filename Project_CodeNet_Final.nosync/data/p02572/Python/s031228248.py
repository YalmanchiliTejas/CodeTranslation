# -*- coding: utf-8 -*-
from itertools import accumulate
def main():
    n = int(input())
    a = list(map(int, input().split()))
    a_sum = (accumulate(reversed(a)))
    a_sum = list(reversed(list(a_sum)))
    sum = 0
    mod = 1000000007
    for i in range(n-1):
        sum += a[i]*a_sum[i+1]
    print(sum%mod)

if __name__ == '__main__':
    main()