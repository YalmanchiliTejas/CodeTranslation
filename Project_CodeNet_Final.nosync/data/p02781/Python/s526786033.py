
from functools import reduce
import operator
product = lambda it: reduce(operator.mul,it,1)

N = input()
K = int(input())

comb = lambda n, k: product(range(n-k+1,n+1))//product(range(1,k+1))

def rec(i, k):
    if k == 0:
        return 1
    if len(N) < k + i:
        return 0
    return (max(0,int(N[i])-1)*(9**(k-1))*comb(len(N)-i-1, k-1) +
            (rec(i+1,k) if N[i] == '0' else rec(i+1,k-1) + (9**k)*comb(len(N)-i-1, k)))

print(rec(0,K))