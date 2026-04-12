from bisect import bisect_left as bl
N=int(input())
A=[int(input()) for _ in [0]*N]
def bl3(A,x):
    # Aは逆順ソートされている
    # x未満のうち最大の要素のインデックスを返す
    ok=len(A)
    ng=-1
    while abs(ok-ng)>1:
        mid=(ok+ng)//2
        if A[mid]<x:
            ok=mid
        else:
            ng=mid
    return ok

B=[A[0]]
for a in A[1:]:
    ind=bl3(B,a)
    if ind==len(B):
        B.append(a)
    else:
        B[ind]=a
print(len(B))