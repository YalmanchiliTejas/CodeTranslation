N=int(input())
H=list(map(int,input().split()))
H.append(0)
max1=H[0]

X=1
for i in range(N):
    if max1 <= H[i+1]:
        X+=1
        max1=H[i+1]
        
print(X)
