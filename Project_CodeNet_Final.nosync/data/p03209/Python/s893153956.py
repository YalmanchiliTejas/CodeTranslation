N,X = map(int,input().split())
def func(N,X):
    if N == 0:
        return 1
    elif X == 1:
        return 0
    elif 2 <= X <= 2**(N+1) -2:
        return func(N-1,X-1)
    elif X == 2**(N+1)-1:
        return 2**N
    elif 2**(N+1) <= X <= 2**(N+2)-4:
        return 2**N + func(N-1,X-(2**(N+1)-1))
    else:
        return 2*(2**N)-1
print(func(N,X))