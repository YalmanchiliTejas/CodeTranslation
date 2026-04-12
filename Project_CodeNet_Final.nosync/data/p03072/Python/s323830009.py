N=int(input())
H=list(map(int,input().split()))
count=1
high=H[0]
for i in range(1,len(H)):
    if high<=H[i]:
        high=H[i]
        count+=1
print(count)