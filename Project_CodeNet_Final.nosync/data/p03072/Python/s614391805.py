N = int(input())

List=list(map(int,input().split()))

sum=1
max=List[0]
for i in List:
    if max<=i:
        max=i
        sum+=1

print(sum-1)
