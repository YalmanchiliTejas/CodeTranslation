N = int(input())
a = list(map(int, input().split()))
cnt = 1
for i in range(1,N):
    o = True
    for j in range(i + 1):
        if a[j] > a[i]:
            o = False
    if o:
        cnt += 1
print(cnt)