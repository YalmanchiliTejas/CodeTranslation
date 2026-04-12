def binary_search(A,func):
    l = 0
    r = len(A)-1
    if func(0,A):return -1
    if not func(r,A):return r
    while l+1<r:
        i = (l+r)//2
        if func(i,A):
            r = i
        else:
            l = i
    return l

N = int(input())
A = [int(input()) for _ in [0]*N]
B = [A[0]]
ans = 1
for a in A[1:]:
    r = binary_search(B,lambda i,b:b[i]<a)+1
    if r < ans:B[r] = a
    else:
        B.append(a)
        ans+=1
print(ans)