N,X,M = map(int, input().split())


A = [-1]*(M+100)
A[0] = X
i = 0
tmpans = 0
flag = False
check = [-1]*(M+1)
slice = -1
while i< N-1:
    newa = A[i]**2%M
    i+= 1
    if check[newa] != -1:
        flag = True
        slice = check[newa]
        break
    A[i] = newa
    check[newa] = i

if not flag:
    print(sum(A[:i+1]))

else:
    print(sum(A[:slice])+ sum(A[slice:i])*((N-slice)//(i-slice))+sum(A[slice:slice + (N-slice)%(i-slice)]))
