N = int(input()) 
A = list(map(int, input().split()))

biggest = 0
humidai = 0

result = 0

tmp_list = []

tmp=sum(A)

for i in range(N-1):

    # for j in range(i+1,N):
        # tmp += A[j]
    tmp -= A[i]
    
    result += A[i]*tmp

    if result>10**9+7:
        result = result%(10**9+7)

result = result%(10**9+7)

print(result)