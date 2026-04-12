def func1(N):
    li = [1] * (N)
    for i in range(N-1):
        li[i+1] = li[i] *2+1
    return(li[N-1])
def func2(N):
    lia = [1] * (N)
    for i in range(N-1):
        lia[i+1] = lia[i] * 2 + 3
    return(lia[N-1])
N,X = [int(i) for i in input().split()]
def f(N,X):
    if N == 0:
        return 0 if X <= 0 else 1
    elif X<=1+func2(N):
        return f(N-1,X-1)
    else:
        return func1(N) + 1 + f(N-1,X-2-func2(N))
print(f(N,X))