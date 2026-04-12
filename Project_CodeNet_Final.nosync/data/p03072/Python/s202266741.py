# B - Great Ocean View(ABC124)
N=int(input())
H=list(map(int, input().split()))
C=0
for i in range(1,N+1):
    if max(H[:i])==H[i-1]:
        C+=1
print(C)