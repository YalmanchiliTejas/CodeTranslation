N=int(input())
lis=[int(x) for x in input().split()]

sum=1
li=[lis[0]]

for i in range(1,N):
    if lis[i] >= max(li):
        sum=sum+1
    li.append(lis[i])

print(sum)