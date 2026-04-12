N=int(input())
mt=list(map(int,input().split(" ")))
count=0
for i in range(N):
    if i==0:
        count +=1
    else:
        if max(mt[:i]) <=mt[i]:
            count +=1

print(count)