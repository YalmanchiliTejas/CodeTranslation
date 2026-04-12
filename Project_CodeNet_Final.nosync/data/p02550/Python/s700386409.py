#!python3

import sys
iim = lambda: map(int, sys.stdin.readline().rstrip().split())

def resolve():
    N, X, M = iim()

    if X == 0:
        print(0)
        return
    A = [X]

    i = 0
    vis = {X: 0}
    while i < N-1:
        a = A[i]**2 % M
        if a in vis:
            break
        elif a == 0:
            print(sum(A))
            return
        A.append(a)
        i += 1
        vis[a] = i
    else:
        a = X

    i = vis[a]
    n = len(A) - i
    a, b = divmod(N-i, n)
    ans = sum(A[i:]) * a
    for j in range(i):
        ans += A[j]
    for j in range(i, i+b):
        ans += A[j]
    print(ans)



if __name__ == "__main__":
    resolve()
