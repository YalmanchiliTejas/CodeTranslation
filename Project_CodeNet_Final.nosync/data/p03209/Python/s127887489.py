import sys

def S(): return sys.stdin.readline().rstrip()

N,X = map(int,S().split())

def f(A,B):  # レベルAバーガーの下からB層に何枚パティがあるか
    if A == 0 and B == 1:
        res = 1
    else:
        if B == 1:
            res = 0
        elif 2 <= B <= 2**(A+1)-2:
            res = f(A-1,B-1)
        elif B == 2**(A+1)-1:
            res = 2**A
        elif 2**(A+1) <= B <= 2**(A+2)-2:
            res = 2**A + f(A-1,B-2**(A+1)+1)
        else:
            res = 2**(A+1)-1
    return res

print(f(N,X))