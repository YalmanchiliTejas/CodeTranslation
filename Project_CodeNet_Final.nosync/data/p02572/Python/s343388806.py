def main():
    from sys import setrecursionlimit, stdin, stderr
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor
    from itertools import accumulate, combinations, combinations_with_replacement
    setrecursionlimit(10**6)
    dbg = (lambda *something: stderr.write("\033[92m{}\033[0m".format(str(something)+'\n'))) if 'TERM_PROGRAM' in environ else lambda *x: 0
    input = lambda: stdin.readline().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    P = 10**9+7
    INF = 10**18+10

    N = II()
    A = LMIIS()

    sum_A = 0
    sum_pow2 = 0
    for a in A:
        sum_A += a
        sum_A %= P
        sum_pow2 += a**2
        sum_pow2 %= P
    
    print((sum_A**2 % P - sum_pow2)%P*pow(2,P-2,P)%P)


    
main()