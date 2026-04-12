from itertools import combinations
import math
N = int(input())
A = list(map(int, input().split()))
mod = 1000000007

def add(a, b):
    return (a + b) % mod

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

def cumsum(xs):
    result = [xs[0]]
    for x in xs[1:]:
        result.append(add(result[-1], x))
    return result

#N = int(input())
#C = input()
#D, T, S=map(int,input().split())
#C = []
#for i in range(N):
#    C.append(list(map(int,input().split())))

inv = cumsum(list(reversed(A)))
c = 0
for i in range(0,N-1):
    c = add(c,mul(A[i],inv[N-i-2]))

print(c)
