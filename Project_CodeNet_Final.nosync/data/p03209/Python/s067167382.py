memo1 = {}
def f(i):
    if i==0:
        return 1
    if i in memo1:
        return memo1[i]
    memo1[i] = 2*f(i-1)+3
    return memo1[i]
memo2 = {}
def g(i):
    if i==0:
        return 1
    if i in memo2:
        return memo2[i]
    memo2[i]=2*g(i-1)+1
    return memo2[i]
N,X = map(int,input().split())
cnt = 0
while X>0 and N>0:
    if X==f(N):
        cnt += g(N)
        X -= f(N)
    elif X>=f(N-1)+2:
        cnt += 1+g(N-1)
        X -= f(N-1)+2
    else:
        X -= 1
    N -= 1
cnt += X
print(cnt)