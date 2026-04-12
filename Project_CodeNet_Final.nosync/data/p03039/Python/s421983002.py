import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
from math import factorial 
def main():
    n, m, k = map(int, readline().split())
    P = int(1e9)+7

    def C(n, m, p):
        a = 1
        for i in range(m):
            a *= (n-i)
            a %= p
        b = factorial(m)%p 
        b = pow(b, p-2, p)
        return a*b%p

    c = C(n*m-2, k-2, P)
    s_x = 0
    for d in range(1, m):
        s_x += d*(m-d)*n*n
        s_x %= P
    s_y = 0
    for d in range(1, n):
        s_y += d*(n-d)*m*m
        s_y %= P

    ans = (s_x+s_y)*c%P
    print(ans)
if __name__ == '__main__':
    main()
