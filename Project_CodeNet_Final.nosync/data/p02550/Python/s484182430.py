n,x,m = map(int,input().split())

if x == 0:
    print(0)
    exit()

li = [-1] * (m+1)
v = [False] * (m+1)
v2 = [False] * (m+1)
v[x] = True
tmp = x
ans = x
loop = 0
cnt = 0
cnt_l = 0
loop_li = [0]
ans_li = [x]

for i in range(m):
    li[i] = (i ** 2) % m

while True:
    tmp = li[tmp]
    ans += tmp
    v[tmp] = True
    cnt += 1
    ans_li.append(ans_li[-1] + tmp)
    if v[li[tmp]]:
        break

while True:
    tmp = li[tmp]
    loop += tmp
    v2[tmp] = True
    cnt_l += 1
    loop_li.append(loop_li[-1] + tmp)
    if v2[li[tmp]]:
        break

cnt -= cnt_l - 1
loop_li = loop_li[1:]
ans_li = ans_li

if n < len(ans_li):
    print(ans_li[n-1])
elif n == len(ans_li):
    print(ans_li[n-1])
else:
    n -= len(ans_li)
    if len(loop_li) == 0:
        print(ans_li[-1])
    else:
        if n % len(loop_li) == 0:
            print(ans_li[-1] + loop_li[-1] * (n//len(loop_li)))
        else:
            print(ans_li[-1] + loop_li[-1] * (n//len(loop_li)) + loop_li[n%len(loop_li)-1])
