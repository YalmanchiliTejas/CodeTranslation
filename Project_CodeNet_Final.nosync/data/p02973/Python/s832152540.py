

from bisect import *



def resolve():
    N = int(input())
    A = [int(input()) for i in range(N)]
    A.reverse()

    B =[A[0]]

    A=A[1:]
    for  i in A:
        if i >= B[-1]:
            B.append(i)
            continue
        point = bisect_right(B,i)
        B[point]=i

    print(len(B))
if __name__ == "__main__":
    resolve()