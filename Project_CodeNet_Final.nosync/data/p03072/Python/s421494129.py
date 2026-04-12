n=int(input())
h=list(map(int,input().split()))
a=h[0]
count=1
for i in range(1,len(h)):
    if h[i]>=a:
        count+=1
        a=h[i]
print(count)