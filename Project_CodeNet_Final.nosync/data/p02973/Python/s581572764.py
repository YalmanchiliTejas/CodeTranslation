import bisect
def main():

    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(input()))
    B = [A[-1]]
    for i in range(N-2, -1, -1):
        if B[-1] <= A[i]:
            B.append(A[i])
        else:
            j = bisect.bisect_right(B, A[i])
            B[j] = A[i]
    return len(B)

if __name__ == '__main__':
    print(main())