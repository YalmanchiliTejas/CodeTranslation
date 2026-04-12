N=int(input())
H=list(map(int,input().split()))

base=H[0]
count=1

for i in range(1,N):
    if H[i]>=base:
        count+=1
        base=H[i]
print(count)
