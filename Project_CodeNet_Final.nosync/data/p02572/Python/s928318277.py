n = int(input())
A = list(map(int,input().split()))

wa = sum(A)
ans = 0
for i in range(n):
    wa -= A[i]
    ans += wa * A[i]

print(ans % ((10**9)+7))