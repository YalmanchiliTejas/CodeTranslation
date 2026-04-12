import math
import collections
def main():

    N, X, M = map(int, input().split())
    visited = dict()
    visited[X] = 0
    A = [X]
    v = X
    j = -1
    isperiod = False
    for i in range(1, N):
        v = (v * v) % M
        if v not in visited:
            visited[v] = i
            A.append(v)
        else:
            j = visited[v]
            isperiod = True
            break

    if isperiod:
        u = sum(A[:j])
        B = A[j:]
        p = len(B)
        u += ((N-j) // p) * sum(B) + sum(B[:(N-j) % p])
        return u
    return sum(A)



if __name__ == '__main__':
    print(main())