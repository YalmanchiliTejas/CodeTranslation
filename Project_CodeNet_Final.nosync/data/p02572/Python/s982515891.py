N = int(input())
A = input().split(' ')
a = 0
sum = 0
for i in range(1, N):
    sum += int(A[i])
for i in range(N):
    a += int(A[i]) *  sum
    if i < N - 1:
        sum -= int(A[i + 1])
    
print(int(a % (10 ** 9 + 7)))