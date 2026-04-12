n = int(input())
h = list(map(int, input().split()))

left = 0
ret = 0
for i in h:
    if i >= left:
        ret += 1
        left = i
print(ret)