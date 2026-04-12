# -*- coding: utf-8 -*-

def LBp(N,X,dLB):
    if N == 0 and X == 1:
        P = 1
    elif N >= 1:
        if X == 1:
            P = 0
        elif 2 <= X <= dLB[N-1]+1:
            P = LBp(N-1,X-1,dLB)
        elif X == dLB[N-1]+2:
            P = LBp(N-1,dLB[N-1],dLB) + 1
        elif dLB[N-1]+3 <= X <= dLB[N]-1:
            P = LBp(N-1,dLB[N-1],dLB) + LBp(N-1,X-dLB[N-1]-2,dLB) + 1
        elif X == dLB[N]:
            P = 2*LBp(N-1,dLB[N-1],dLB) + 1
    return P

def solve():
    N, X = map(int, input().split())
    dLB = [1]
    for i in range(1,N+1):
        dLB[i:] = [2*dLB[i-1]+3]
    res = LBp(N,X,dLB)
    return str(res)

if __name__ == '__main__':
    print(solve())