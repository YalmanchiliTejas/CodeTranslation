N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
A.reverse()

def binary_search(lis,i):
    ng = 0
    ok = len(lis)-1
    while abs(ok-ng) > 1:
        #print(ok,ng)
        mid = (ok + ng) // 2
        if lis[mid] > i:
            ok = mid
        else:
            ng = mid
    return ok

#print(A)
d = [-1,1000000007]
for i in range(N):
    p = binary_search(d,A[i])
    if p == len(d)-1:
        d.append(A[i])
        d[-1],d[-2] = d[-2],d[-1]
    else:
        d[p] = A[i]
    #print(p)
    #print(d)
print(len(d)-2)
