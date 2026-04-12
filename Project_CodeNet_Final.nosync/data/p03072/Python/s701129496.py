n=int(input())
arr = list(map(int, input().split()))
re=0
com=0
for i in range(n):
    if arr[i]>=com:
        re+=1
        com=arr[i]
print(re)
