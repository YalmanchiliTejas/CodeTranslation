N=int(input())
A=list(map(int,input().split()))
ans = 0
last = 0

for i in range(N):
    ans += A[i]*A[i]
last += sum(A)*sum(A)
last -= ans
last //= 2
print(last % 1000000007)