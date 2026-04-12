n = int(input())
A = list(map(int,input().split()))

a = A[::-1]
s = [0]*(n+1)

for i in range(n):
    s[i+1] = s[i] + a[i]

s = s[:n]
s = s[::-1]

tot = 0
for i in range(n-1):
    tot += A[i]*s[i]
    
print(tot%(10**9+7))
