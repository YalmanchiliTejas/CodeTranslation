n = int(input())
hlis = list(map(int, input().split()))
hlis.reverse()

cnt = 0
for i in range(n):
    tmp = "ok"
    for j in range(i+1,n):
        if hlis[i]<hlis[j]:
            tmp = "ng"
    if tmp == "ok":
        cnt = cnt + 1
        
print(cnt)