n=int(input())
h=list(map(int,input().split()))

max_height=h[0]
count=1

for i in range(1,n):
    max_height=max(h[i-1],max_height)
    if h[i]>=max_height:
        count +=1

print(count)