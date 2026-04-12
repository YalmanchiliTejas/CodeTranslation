N=int(input())
H=[int(h) for h in input().split()]

Hmax=H[0]
count=1
for i in range(1,N):
    if Hmax<=H[i]:
        count+=1
        Hmax=H[i]
print(count)