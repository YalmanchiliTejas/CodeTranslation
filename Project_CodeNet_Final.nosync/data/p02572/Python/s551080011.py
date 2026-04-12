N = int(input())
A = list(map(int,input().split()))

k = 1000000007

sm = sum(A)

ans = 0
for s in range(len(A)-1):
    #ans += A[s]*sum(A[s+1:])
    sm -= A[s]
    ans += A[s]*sm

if ans>1000000007:
    print(ans%k)
else:
    print(ans)
