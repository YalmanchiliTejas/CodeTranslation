n=int(input())
list_h=list(map(int,input().split()))
list_max=[]
count=1
for i in range(1,n):
    list_p=list_h[:i]
    if max(list_p)<=list_h[i]:
        count=count+1
print(count)

