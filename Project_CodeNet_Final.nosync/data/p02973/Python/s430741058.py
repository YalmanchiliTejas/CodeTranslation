N = int(input())
A = list(int(input())for i in range(N))
H = [A[0]]
for i in range(1,N):
    if A[i] <= H[-1]:
        H.append(A[i])
    else:
        l,r =0,len(H)
        while l != r :
            if H[(l+r)//2]>=A[i]:
                l = (l+r)//2+1
            else:
                r = (l+r)//2
        H[l] = A[i]
print(len(H))
