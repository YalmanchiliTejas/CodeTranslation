n,x,m = map (int,input().split())
next=[0] * (m+1)
memo = [-1] * (m+1)
memo[x] = 0
a = 0
now = x
unti = [x]
flag = True
b = -1
for i in range(m):

    next[now] = (now **2) % m
    #print(1,next)
    if memo[next[now]]!=-1:
        b = memo[next[now]]
        break
    elif next[now] == 0:
        flag =False
        break
    else:
        memo[next[now]] = i+1
    a += 1
    now = next[now]
    unti.append(now)
if flag:
    if b== 0:
        if (n-b)%(a-b+1) !=0:
            print(sum(unti[b:a+1]) * ((n - b) // (a - b + 1)) + sum(unti[b:b+(n - b) % (a - b + 1)]))
        else:
            print(sum(unti[b:a+1]) * ((n - b) // (a - b + 1)))
    else:
        if (n - b) % (a - b + 1) != 0:
            print(sum(unti[b:a+1]) * ((n-b)//(a-b+1)) + sum(unti[b:b+(n-b)%(a-b+1)])  + sum(unti[:b]))
        else:
            print(sum(unti[b:a + 1]) * ((n - b) // (a - b + 1)) + sum(unti[:b]))
else:
    print(sum(unti))
