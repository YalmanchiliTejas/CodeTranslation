import sys
sys.setrecursionlimit(10000)
def resolve():
    A, B, C, X, Y = list(map(int, input().split(" ")))
    if A + B < 2 * C:
        print(A*X+B*Y)
        return
    if X < Y:
        m = min((Y-X)*B, 2*(Y-X)*C)
        print(2*X*C+m)
        return
    else:
        m = min((X-Y)*A, 2*(X-Y)*C)
        print(2*Y*C+m)
        return

    
    
if '__main__' == __name__:
    resolve()