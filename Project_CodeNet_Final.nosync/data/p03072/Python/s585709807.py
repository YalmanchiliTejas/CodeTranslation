N = int(input())
lists = list(map(int,input().split()))
cnt = 1
for i in range(1,N):
    if lists[i-1] <= lists[i]:
        cnt += 1
    else:
        lists[i] = lists[i-1]
print(cnt)