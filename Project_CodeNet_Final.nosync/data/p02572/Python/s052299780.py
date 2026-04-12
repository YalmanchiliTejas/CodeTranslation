x = input()
N = int(x)
A = list(map(int,input().split()))
a = 0
b = 0

for i in range(N-1):
    a = a + A[i+1]

for i in range(N-1):
    b = b + A[i]*a
    a = a - A[i+1]

print(b % (10**9+7))
