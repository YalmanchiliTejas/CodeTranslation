n=int(input())
h=[int(i) for i in input().split()]
count=n
for i in reversed(range(1,n)):
    for j in reversed(range(0,i)):
        #print(count)
        #print(h[i],h[j])
        if h[i]<h[j]:
            count-=1
            break
print(count)