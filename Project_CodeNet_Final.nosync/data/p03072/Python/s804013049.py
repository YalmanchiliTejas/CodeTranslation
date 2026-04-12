n=int(input())
ls=list(map(int,input().split()))
count=0
max=0
for i in ls:
    if i>=max:
        count+=1
        max=i
print(count)