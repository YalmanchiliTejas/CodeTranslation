N=int(input())
H=input().split()
H=[int(i) for i in H]
cnt=1
key=False

for i in range(N):
    for j in range(i):
        if H[i]<H[j]:
            key=False
            break
        else:
            key=True
    if key==True:
        cnt+=1
    key=False
    
print(cnt)