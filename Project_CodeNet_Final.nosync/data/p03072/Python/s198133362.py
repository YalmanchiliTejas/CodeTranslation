n=int(input())
h_list=list(map(int, input().split()))
max_h=0
sum=0
for i in range(n):
    if max_h<=h_list[i]:
        sum=sum+1
        max_h=h_list[i]

print(sum)
