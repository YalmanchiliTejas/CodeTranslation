import bisect
from collections import deque

n = int(input())
lis = deque()

ans = 0
for i in range(n):
    a = int(input())
    if i == 0:
        lis.append(a)
        continue
    l = bisect.bisect_left(lis,a)
    r = bisect.bisect_right(lis,a)
    if l != r :#同じものがある
        if l > 0:#他の色の最大値が上書きできる
            lis[l-1]=a
        elif r ==  len(lis):#全部の色の最大値とaが同じなら追加
            lis.append(a)
        else:#どこかの中に挿入
            lis.appendleft(a)
    elif l == 0:#最小値追加
        lis.appendleft(a)
    else:#最大値更新
        lis[r-1] = a
print(len(lis))