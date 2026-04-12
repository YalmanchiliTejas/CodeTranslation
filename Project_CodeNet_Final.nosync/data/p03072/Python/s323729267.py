n=int(input())
h=list(map(int,input().split()))
count=0
j=h[0]
for i in h:
    if j<=i:
        count+=1
        j=i
print(count)