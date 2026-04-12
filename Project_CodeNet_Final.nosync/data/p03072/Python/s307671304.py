N=int(input())
mou=list(map(int,input().split()))

top=mou[0]
count=0

for i in range(N):
    if mou[i]>=top:
        count+=1
        top=mou[i]
    
print(count)
