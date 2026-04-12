n = int(input())
a = [int(x) for x in input().split()]

sm_e = []
sm_o = []

e = 0
o = 0

for i in range(n):
    if i % 2 == 0:
        e += a[i]
        sm_e.append(e)
    else:
        o += a[i]
        sm_o.append(o)

tot_e = sm_e[-1]
tot_o = sm_o[-1]

m = len(sm_o)

if n % 2 == 0:
    ans = max(tot_e, tot_o)
    for i in range(m):
        ans = max(ans, sm_e[i] + tot_o - sm_o[i])
    # for i in range(m-1):
    #     ans = max(ans, sm_o[i] + tot_e - sm_e[i+1])
    print(ans)
    exit()

ans = tot_o

for i in range(m):
    ans = max(ans, sm_e[i]+tot_o-sm_o[i])


l = [0]*m
for i in range(m):
    l[i] = sm_e[i]-sm_o[i]

val = l[0]
tmp = 0

for i in range(m-1):
    ans = max(ans, sm_o[i] + tot_e - sm_e[i+1])
    if i != 0:
        if val < l[i]:
            val = l[i]
    ans = max(ans, sm_o[i] + tot_e - sm_e[i+1] + val)

for i in range(n):
    if i % 2 == 0:
        ans = max(ans, tot_e - a[i])

print(ans)
