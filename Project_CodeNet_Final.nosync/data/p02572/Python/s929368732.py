N = int(input())
A = list(map(int, input().split()))
t = 0 
S = sum(A)
c = 0 
for i in range(len(A) - 1): 
        S -= A[i]
        t = (t + (A[i] * S))
print(t % 1000000007)