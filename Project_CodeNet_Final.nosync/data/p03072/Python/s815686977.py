N=int(input())
H=list(map(int,input().split()))
high=H[0]
count=1
for i in range(1,N):
    if high<=H[i]:
        count=count+1
        high=H[i]
    else:
        pass
print(count)
