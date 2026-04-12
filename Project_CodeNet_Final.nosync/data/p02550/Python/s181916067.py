def f(x, m):
    return x * x % m

def main():
    N, X, M = map(int, input().split())
    pre = set()
    pre.add(X)
    cnt = 1
    while cnt < N:
        X = f(X, M)
        if X in pre: break
        cnt += 1
        pre.add(X)
    if cnt == N:
        return sum(pre)
    ans = sum(pre)
    N -= cnt
    loop = set()
    loop.add(X)
    while cnt < N:
        X = f(X, M)
        if X in loop: break
        loop.add(X)
    
    left = N % len(loop)
    ans += sum(loop) * (N // len(loop))
    for i in range(left):
        ans += X
        X = f(X, M)
    return ans

print(main())
