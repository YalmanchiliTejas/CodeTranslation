N = int(input())
A = [int(e) for e in input().split()]

S = [0]
sum =0
for i in range(0, N):
    S.append(S[i] + A[i])
for i in range(N):
    sum = sum + (S[i+1]-A[i]) * A[i]
print(sum%1000000007)