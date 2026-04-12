N=int(input())
li=list(map(int,input().split()))
#print(li)
vi=1
maxi=li[0]
for i in range(1,N):
    if maxi<=li[i]:
        maxi=li[i]
        vi+=1
print(vi)