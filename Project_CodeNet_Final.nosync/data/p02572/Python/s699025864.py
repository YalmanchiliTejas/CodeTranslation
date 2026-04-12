#C
N = int(input())
A = list(map(int, input().split()))
result = sum(A)**2
for i in A:
    result -= i**2
print((result//2)%1000000007)