import collections as c
ip = lambda : map(int, input().split())

#################
N = int(input())
ls = list(map(int, input().split()))
h = 0
ans = 0
for i in ls:
    if i>=h:
        ans += 1
    h = max(h,i)
print(ans)