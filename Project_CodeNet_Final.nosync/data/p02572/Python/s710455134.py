N = int(input())
A = list(map(int,input().split()))
left =0
right = 0
tmp = 0
for i in range(0,N-1):
    left = A[N-2-i]
    right = right + A[N-1-i]
    tmp += left * right

print(tmp%((10**9) + 7))