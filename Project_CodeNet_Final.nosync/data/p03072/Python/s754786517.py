N = int(input())
mnt = [int(i) for i in input().split()]
cnt = 0
for i,x in enumerate(mnt):
    if max(mnt[0:i+1]) == x:
        cnt += 1
print(cnt)