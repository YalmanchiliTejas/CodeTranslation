N=int(input())
H=list(map(int,input().split()))
x=1
for i in range(1,N):
    is_count=True
    for j in range(i):
        if H[j] > H[i]:
            is_count=False
            break
    if is_count:
        x+=1
print(x)
