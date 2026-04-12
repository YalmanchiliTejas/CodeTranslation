n=int(input())
h=list(map(int,input().split()))
k=0
ct=0
for i in range(n):
    if k<=h[i]:
        ct+=1
        k=h[i]
    else:
        pass
print(ct)