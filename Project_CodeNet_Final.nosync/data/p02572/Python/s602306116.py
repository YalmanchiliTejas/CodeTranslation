N = int(input())
A = [int(x) for x in input().split()]
sup = 10**9 + 7 
sumA = 0
total = 0

for i in range(0,N-1):
    sumA += A[i]
    if sumA > sup:
        sumA %= sup
    total += sumA*A[i+1]
    if total > sup:
        total %= sup

print(total)