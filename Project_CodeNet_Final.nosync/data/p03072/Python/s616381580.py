n=int(input())
h=list(map(int,input().split()))
h.insert(0,0)
#print(h)
count=0
for i in range(n+1):
    if len(h[:i]):
        if h[i-1]<=h[i] and max(h[:i])<=h[i]:
            #print(h[i])
            count+=1
print(count)