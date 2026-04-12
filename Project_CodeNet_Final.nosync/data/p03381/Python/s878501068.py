N = int(input())
A = list(map(int, input().split()))
B = A.copy()
B.sort()
a = B[N//2-1]
b = B[N//2]

if a == b:
    for i in range(N):
        print(a)
else:
    for i in range(N):
        if A[i] <= a:
            print(b)
        else:
            print(a)