K, A, B = [int(i) for i in input().split()]
if(K <= A):
    print(1)
else:
    if(A-B <= 0):
        print(-1)
    else:
        print(1+(K-B-1)//(A-B)*2)
