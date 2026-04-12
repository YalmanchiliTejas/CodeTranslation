import sys
input = sys.stdin.readline

def main():
    N = int(input())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())
    A.sort()

    tmp = N // 2
    if N % 2 == 1:
        L, M, R = A[:tmp], A[tmp], A[tmp+1:]
        # max(R[0]の隣にMを配置, L[-1]の隣にMを配置)
        print((sum(R) - sum(L)) * 2 + max(L[-1] - M, M - R[0]))
    else:
        L, R = A[:tmp], A[tmp:]
        """
        L[-1], R[0]は、第1項で
        それぞれ1回多く計算されているため、
        (L[-1] - R[0])としている
        """
        print((sum(R) - sum(L)) * 2 + (L[-1] - R[0]))

if __name__ == "__main__":
    main()