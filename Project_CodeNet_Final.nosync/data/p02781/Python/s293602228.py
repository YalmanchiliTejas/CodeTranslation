import sys
from math import factorial

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
K = ir()
length = len(str(N))

def F(length, K, N):
    if length < K:
        return 0
    if K == 0:
        return 1
    if length == 1: #この時、Kも1
        return N
    ret = 0
    top = int(str(N)[0])
    if length-K >= 1:
        ret += factorial(length-1) // factorial(K) // factorial(length-K-1) * 9 ** K # 一個前まで    
    ret += factorial(length-1) // factorial(K-1) // factorial(length-K) * (top-1) * 9 ** (K-1) # 一桁目がtopより小さい数  
    # 一桁目がtopと同じ数
    if K > 1: 
        N = int(str(N)[1:])
        length = len(str(N))
        ret += F(length, K-1, N)
    else:
        ret += 1 # 2000のような数
    return ret

answer = F(length, K, N)
print(answer)
