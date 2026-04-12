N = int(input())
H = list(map(int, input().split()))
A = 0
for i in range(N):
    if max(H[0:i+1]) <= H[i]:
        A = A+1

print(A)