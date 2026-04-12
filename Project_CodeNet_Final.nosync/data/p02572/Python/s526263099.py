N = int(input())
A = list(map(int, input().split())) 
 
goukei = 0

sumA = sum(A)
for i in range(N):
    a = A[i]
    sumA = sumA - a
    goukei = goukei + sumA*a

k = 10**9 + 7
print(goukei%k)