def main():

    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(input()))
    A.sort()

    if N % 2 == 0:
        A1 = A[:N//2]
        A2 = A[N//2:][::-1]
        B1 = []
        B2 = []
        k, l = 0, 0
        for i in range(N):
            if i % 2 == 0:
                B1.append(A1[k])
                B2.append(A2[k])
                k += 1
            else:
                B1.append(A2[l])
                B2.append(A1[l])
                l += 1
        B1 = [B1[-1]] + B1[:-1]
        B2 = [B2[-1]] + B2[:-1]

        cand1, cand2 = 0, 0
        for i in range(1, N):
            cand1 += abs(B1[i-1]-B1[i])
            cand2 += abs(B2[i-1]-B2[i])
        return max(cand1, cand2)
    else:
        A3 = A[:N//2]
        A4 = A[N//2:][::-1]
        A5 = A[:(N+1)//2]
        A6 = A[(N+1)//2:][::-1]
        B3 = []
        B4 = []
        k, l = 0, 0
        for i in range(N):
            if i % 2 == 0:
                B3.append(A4[k])
                B4.append(A5[k])
                k += 1
            else:
                B3.append(A3[l])
                B4.append(A6[l])
                l += 1
        B3 = [B3[-1]] + B3[:-1]
        B4 = [B4[-1]] + B4[:-1]

        cand3, cand4 = 0, 0
        for i in range(1, N):
            cand3 += abs(B3[i-1]-B3[i])
            cand4 += abs(B4[i-1]-B4[i])
        return max(cand3, cand4)


if __name__ == '__main__':
    print(main())