def parse_input(raw,format):
    raw=raw.split()
    format=format.split()

    ret={}
    rawpos=0
    for f in format:
        pass


def A(S):
    ret=700
    ret+=S.count("o")*100
    return ret

def B(N,X,m):
    ret=0
    X-=sum(m)
    ret+=len(m)

    ret+=int(X/min(m))

    return ret

def C(A,B,C,X,Y):
    both_price=min(A+B,C*2)
    A_price=min(A,C*2)
    B_price=min(B,C*2)

    both_num=min(X,Y)
    X_num=X-both_num
    Y_num=Y-both_num
    return both_price*both_num+X_num*A_price+Y_num*B_price

import sys

inp = sys.stdin.read().split()
inp=[int(i) for i in inp]
print(C(inp[0], inp[1], inp[2],inp[3],inp[4]))

