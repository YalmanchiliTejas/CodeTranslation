import sys
input = sys.stdin.readline

n = int(input())
a = [int(input()) for _ in range(n)]

li = [a[0]]
ans = 1

for i in range(1,n):
    if li[0] < a[i]:
        li[0] = a[i]
    elif li[-1] >= a[i]:
        li.append(a[i])
    else:
        p = 0
        q = len(li) - 1
        while p != q:
            c = (p + q) // 2
            if li[c] >= a[i]:
                p = c + 1
            else:
                q = c
        li[p] = a[i]

print(len(li))
