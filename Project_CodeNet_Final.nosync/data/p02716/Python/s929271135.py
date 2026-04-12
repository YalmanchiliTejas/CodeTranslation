def find(A):
    N = len(A)
    ans = [0]*N
    odd_sum = [0]*N
    even_sum = [0]*N
    for i in range(N):
        if i%2 == 0:
            if i-2>=0:
                even_sum[i] = even_sum[i-2] + A[i]
            else:
                even_sum[i] = A[i]
        else:
            if i-2>=0:
                odd_sum[i] = odd_sum[i-2] + A[i]
            else:
                odd_sum[i] = A[i]

#     print(odd_sum)
#     print(even_sum)
    for i in range(1,N):
        length = i+1
        if length%2==0:
            ans[i] = max(A[i] + ans[i-2],odd_sum[i-1]+even_sum[i-1] )
        else:
            ans[i] = max(A[i] + ans[i-2],ans[i-1])
            
    return ans[-1]
    
input()   
print(find(list(map(int,input().strip().split()))))