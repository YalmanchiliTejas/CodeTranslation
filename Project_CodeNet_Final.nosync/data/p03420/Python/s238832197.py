N, K = map(int, input().split())

def f(x, y):
    a, b = divmod(x,y)
#    print("aa",b*(a+1))
    return y*a*(a+1)//2 + (b+1)*(a+1)

r = 0
for b in range(K+1, N+1):
#    print(f(N-K, b), f(N-b, b))
    r += f(N-K, b)- f(N-b, b)
    if K == 0:
        r -= 1
#    print(b, N-b+1, N-K+1)
#    print(b, (N-K)//b, (N-b)//b, (N-K)%b, (N-b)%b, b-K)
#    for j in range(N-b+1,N-K+1):
#        r += j//b + 1
print(r)
