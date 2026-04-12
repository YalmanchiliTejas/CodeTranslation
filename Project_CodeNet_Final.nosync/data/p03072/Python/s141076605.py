count_mountain=int(input())
top=list(map(int,input().split()))
hardle=0
count=0
for x in top:
    if hardle<=x:
        count+=1
        hardle=x
print(count)
