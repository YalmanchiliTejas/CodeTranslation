N = int(input())
A = []
A += list(map(int,input().split()))
S = 0
k = 0

Dum = 0
Gum = 0

for i in range(0, N-1):
    Dum += A[i]
    Gum += Dum * A[i+1]

print(Gum % 1000000007)