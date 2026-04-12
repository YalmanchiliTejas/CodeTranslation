n = int(input())
h = list(map(int,input().split()))
cnt = 0
x = 0
for i in h:
    if i>=x:
        cnt += 1
    x = max(i,x)   
print(cnt)