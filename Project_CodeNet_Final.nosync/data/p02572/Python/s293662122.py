 
N = int(input())

A = list(map(int,input().split()))

B = []

B_val = 0

ans = 0

for i in A[::-1]:
    B.append(B_val)
    B_val += i

for i in range(N):
    ans += ( A[i] * B[-i-1] ) % (1000000000 + 7 )

print(ans % (1000000000 + 7 ) )
