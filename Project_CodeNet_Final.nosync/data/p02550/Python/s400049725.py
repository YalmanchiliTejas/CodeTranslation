n, x, m = map(int, input().split())
lis = set()
loop_lis = []
cnt = 0
while x not in lis:
    cnt += 1
    lis.add(x)
    loop_lis.append(x)
    x = pow(x, 2) % m
    if cnt == n:
        print(sum(lis))
        exit()

start = loop_lis.index(x)
length = len(loop_lis) - start
loop_sum = sum(loop_lis[start:])
before = sum(loop_lis[:start])
loop = loop_sum * ((n - start) // length)
remain = sum(loop_lis[start : (start + (n - start) % length)])

print(before + loop + remain)
