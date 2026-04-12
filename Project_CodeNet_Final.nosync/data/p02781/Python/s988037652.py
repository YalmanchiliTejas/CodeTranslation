import sys
from math import factorial

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

N = ir()
K = ir()
length = 0
for i in range(1, 102):
    if 10 ** i > N:
        length = i
        break

answer = 0
def F(length, K, N):
    ret = 0
    if length == 1:
        if K == 1:
            return N
        elif K == 0:
            return 1
        else:
            return 0
    if length < K:
        return 0
    top = int(str(N)[0])
    if length-K >= 1:
        ret += factorial(length-1) // factorial(K) // factorial(length-K-1) * 9 ** K # 一個前まで    
    ret += factorial(length-1) // factorial(K-1) // factorial(length-K) * (top-1) * 9 ** (K-1) # 一桁目がtopより小さい数  
    if K > 1: # 一桁目がtopと同じ数
        N = int(str(N)[1:])
        length = 0
        for i in range(1, 100):
            if 10 ** i > N:
                length = i
                break
        ret += F(length, K-1, N)
    else:
        ret += 1 # 2000のような数
    return ret

answer = F(length, K, N)
print(answer)
