N=int(input())
H=[int(i) for i in input().split()]
k=0
l=0
for j in range(N):
    if H[l]<=H[j]:
        k+=1
        l=j
print(k)