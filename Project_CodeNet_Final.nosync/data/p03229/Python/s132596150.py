N = int(input())
A = [int(input()) for x in range(N)]
A.sort()
l = len(A)//2
if  len(A)%2 == 1:
    one = 2*sum(A[l+1::])-2*sum(A[:l+1:])+A[l-1]+A[l]
    two = 2*sum(A[l::])-2*sum(A[:l:])-A[l]-A[l+1]
    print(max(one,two))
else:
    print(2*sum(A[l::])-2*sum(A[:l:])-A[l]+A[l-1])
