n=int(input())
A=list(map(int,input().split()))
maximum_at=0
count=0
for i in range(n):
    if A[i]>=maximum_at:
        count+=1
    maximum_at=max(maximum_at,A[i])
print(count)