N=int(input())
A=list(map(int,input().split()))

sum_array=[]
total=0
temp_sum=sum(A)
for i in range(N-1):
    temp_sum=temp_sum-A[i]
    sum_array.append(temp_sum)
    total+=A[i]*sum_array[i]

print(total % (10**9 + 7))