n = int(input())
a = list(map(int,input().split()))
maxa = a[0]
cnt = 0
for i in range(n):
    if a[i]>=maxa:
        cnt +=1
        maxa = a[i]
print(cnt)