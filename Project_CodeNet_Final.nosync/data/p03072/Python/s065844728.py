n=int(input())
H=list(map(int,input().split()))

c=1
maxh=H[0]
for i in range(1,len(H)):
    if maxh<=H[i]:
        c+=1
        maxh=H[i]
print(c)