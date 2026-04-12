if __name__ == '__main__':
    MODULO = 10**9 + 7
    n = int(input())
    A = list(map(int, input().split()))
    total = 0
    sq = 0
    for i in range(n):
        total = (total + A[i]) #% MODULO
        sq = (pow(A[i], 2) + sq) #% MODULO
    total = ((pow(total, 2) - sq) // 2) % MODULO
    print(total )

