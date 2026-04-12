def binary_search(data, value):
    left = 0            # 探索する範囲の左端を設定
    right = len(data) - 1            # 探索する範囲の右端を設定
    while left <= right:
        mid = (left + right) // 2            # 探索する範囲の中央を計算
        if data[mid] == value:
            # 中央の値と一致した場合は位置を返す
            return mid
        elif data[mid] < value:
            # 中央の値より大きい場合は探索範囲の左を変える
            left = mid + 1
        else:
            # 中央の値より小さい場合は探索範囲の右を変える
            right = mid - 1
    return -1            # 見つからなかった場合

import heapq

n,x,mod = map(int,input().split())
c = [x]
heapq.heapify(c)
cc = [x]
num = x
count = 1
while True:
    num = pow(num, 2, mod)
    if binary_search(c, num) != -1:
        b = cc.index(num)
        l = count - b
        cycle = cc[b:]
        startl = b
        start = cc[:b]
        break
    count += 1
    heapq.heappush(c, num)
    cc.append(num)

# print(cc)
# print(cycle,l)
# print(start,startl)
ans = 0
if n <= startl:
    for i in range(n):
        ans += start[i]
    print(ans)
else:
    ans += sum(start)
    n -= startl
    # print(n)
    syo = n // l
    amari = n % l
    s = [0]*(l+1)
    for i in range(1,l+1):
        s[i] = s[i-1] + cycle[i-1]
    ans += s[l]*syo + s[amari]
    print(ans)