def count(n, x):
    b1 = 1<<n
    b2 = b1<<1
    return 1 if n == 0 else \
           0 if x == 1 else \
           count(n-1, x-1) if x <b2-1 else \
           b1 if x == b2-1 else \
           count(n-1, x+1-b2)+b1 \

N, X = map(int, input().split())
print(count(N, X))
