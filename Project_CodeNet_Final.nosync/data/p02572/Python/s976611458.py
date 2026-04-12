from copy import copy

N = int(input())
A = list(map(int, input().split()))
S,r,m = [0]*N,0,1000000007

for i in range(len(A)-1):
    S[N-2-i] = S[N-1-i] + A[N-1-i] 

for a,s in zip(A,S):
    r += (a*s)%m
    r %= m

print(r)