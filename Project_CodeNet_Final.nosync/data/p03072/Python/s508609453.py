n=int(input())
li = list(map(int,input().split()))


count=0
for i in range(n):
    if max(li[0:i+1])==li[i]:
        count+=1
        
print(count)


