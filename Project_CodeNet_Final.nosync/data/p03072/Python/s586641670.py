n=int(input())
c=list(map(int, input().split()))
count=1
for i in range(n-1):
    if c[i]<=c[i+1]:
        count+=1
    else:
        c[i], c[i+1] = c[i+1], c[i]
print(count)