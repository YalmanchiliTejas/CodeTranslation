# -*- coding: utf-8 -*-

def f(N,k):
    if not N:
        return 0
    N = str(int(N))
    a = (len(N)-1)
    na = int(N[0])
    if k == 1:
        return str(9*a+na)
    if k == 2:
        return str(9**2*a*(a-1)//2 + (na-1)*int(f('9'*a,1)) + int(f(N[1:],1)))
    if k == 3:
        return str(9**3*a*(a-1)*(a-2)//6 + (na-1)*int(f('9'*a,2)) + int(f(N[1:],2)))

def solve():
    N = input()
    K = int(input())
    return f(N,K)
    
if __name__ == '__main__':
    print(solve())