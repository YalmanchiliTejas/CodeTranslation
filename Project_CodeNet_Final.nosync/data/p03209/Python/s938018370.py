#coding:utf-8
import sys,os
sys.setrecursionlimit(10**6)
write = sys.stdout.write
dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in os.environ else lambda *x: 0
def main(given=sys.stdin.readline):
    input = lambda: given().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    XLMIIS = lambda x: [LMIIS() for _ in range(x)]
    YN = lambda c : print('Yes') if c else print('No')
    MOD = 10**9+7

    
    N,X = LMIIS()
    p = [1]*(N+1)
    a = [1]*(N+1)
    for i in range(1,N+1):
        p[i] = p[i-1] * 2 + 1
        a[i] = a[i-1] * 2 + 3
    


    def f(i,y):
        if i == 0:
            return 1
        if y == 1:
            return 0
        if 1 < y <= 1 + a[i-1]:
            return f(i-1,y-1)
        if y == 2 + a[i-1]:
            return p[i-1] + 1
        if 2 + a[i-1] < y <= 2 + a[i-1]*2:
            return p[i-1] + 1 + f(i-1,y-(2+a[i-1]))
        else:
            return p[i-1] * 2 + 1

    print(f(N,X))

    



if __name__ == '__main__':
    main()