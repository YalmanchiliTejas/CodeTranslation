N=int(input())
H=list(map(int,input().split()))
#N=5
#H=[10,7,37,69,5]
Max=0
count=0
for i in range(N):
    if H[i]>=Max:
        Max=H[i]
        count+=1
print(count)
