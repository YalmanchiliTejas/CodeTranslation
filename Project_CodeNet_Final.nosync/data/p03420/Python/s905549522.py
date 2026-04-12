#coding:utf-8
import sys,os
from collections import defaultdict, deque
from fractions import gcd
from math import ceil, floor
sys.setrecursionlimit(10**6)
write = sys.stdout.write
dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in os.environ else lambda *x: 0
def main(given=sys.stdin.readline):
    input = lambda: given().rstrip()
    MIIS = lambda: map(int,input().split())
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    XLMIIS = lambda x: [LMIIS() for _ in range(x)]
    YN = lambda c : print('Yes') if c else print('No')
    MOD = 10**9+7

    N,K = MIIS()
    #NからK+1
    # a % b = K + x (x = 0 ... b-K-1) (K+1<=b)
    # a // b = y (y=0...(N-K)//b)
    ans = 0
    # for i in range(K+1,N+1):
    #     diff = ((N-K)//i+1) * (i-K)
    #     print(i,diff,i-K-1,i-K)
    #     ans += ((N-K)//i+1) * (i-K)
    # print(ans)
    ans = 0
    # for b in range(1,N+1):
    #     for a in range(1,N+1):
    #         # write(str('|{} {} {}| '.format(a,b,a % b >= K)))
    #         if a % b >= K:
    #             ans += 1
    #     print()
    ans2 = 0
    for b in range(K+1,N+1):
        ans2 += (N//b)*(b-K)
        # print(b,N//b*b+1,max(N - (N//b*b + K) +1,0))

        
        ans2 += max(N - (N//b*b + K) +min(1,K),0)
        # for r in range(N//b*b+1,N+1):
            
        #     if r % b >= K:
        #         ans2 += 1
        #     else:
        #         print('a!',r,b)
        # write(str('|{} {}| '.format(b,(N//b)*(b-K)+max((N%b)-K,0))))
        # print()
    
    print(ans2)

    

if __name__ == '__main__':
    main()