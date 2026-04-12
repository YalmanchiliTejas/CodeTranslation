n=int(input())
lst = list(map(int, input().split()))
cnt=0
max=lst[0]
for i in range(n):
    if max<=lst[i]:
        max=lst[i]
        cnt+=1
print(cnt)
    
