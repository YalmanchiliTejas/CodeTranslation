N = int(input())
A = list(map(int, input().split()))
C = 10**9+7
s = (sum(A[i]**2 for i in range(N))) % C
t = (sum(A)**2) % C
print(((t-s)*pow(2, C-2, C)) % C)
