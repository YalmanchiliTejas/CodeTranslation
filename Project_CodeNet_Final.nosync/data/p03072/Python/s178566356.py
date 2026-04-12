N=int(input())
H=list(map(int,input().split()))
a=0
for i in range(N):
    if all(H[j]<=H[i] for j in range(i))==True:
        a+=1
print(a)