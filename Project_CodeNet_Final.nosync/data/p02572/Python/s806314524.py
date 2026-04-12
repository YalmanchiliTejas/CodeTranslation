N = int(input())
A = list(map(int,input().split()))
summ1 = 0
answer = 0
temp = 0
summ2 = 0
summ3 = 0
for i in range(N):
    summ1 += A[i]
for l in range(N):
    summ3 += A[l]
    summ2 += A[l]*(summ1-summ3)
answer = summ2 % 1000000007
print(answer)