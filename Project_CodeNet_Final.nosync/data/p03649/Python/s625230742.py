import heapq


n = int(input())
a = list(map(int, input().split()))

cnt = 0
while True:
    max_a = max(a)
    max_ind = a.index(max_a)
    if max_a <= n-1:
        break
    decrease = max_a // n
    max_a = max_a % n
    for i in range(n):
        if i == max_ind:
            a[i] = max_a
        else:
            a[i] += decrease
    cnt += decrease
    
    min_a = min(a)
    min_ind = a.index(min_a)    
    if min_a <= n-1:
        continue
    decrease = min_a - (n - 1)
    for i in range(n):
        a[i] -= decrease
    cnt += decrease * n

print(cnt)