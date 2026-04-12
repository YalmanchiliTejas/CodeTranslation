n = int(input())
a = [int(c) for c in input().split()]
m = 0
t0 = [-1]*n # 最初使える、i以降
t1 = [-1]*n # 使えない
t2 = [-1]*n # 使わないといけない
t0[-1] = a[-1]
t1[-1] = 0
t2[-1] = a[-1]
tmp = 0
for i in range(-1, -n-1, -2):
    tmp += a[i]
    t2[i] = tmp
tmp = 0
for i in range(-2, -n-1, -2):
    tmp += a[i]
    t2[i] = tmp

    
for i in range(-2, -n-1, -1):
    if i%2==0:
        m= a[i]+t1[i+1]
        m = max(m, t2[i+1])
        t0[i] = m
        t1[i] = t0[i+1]
#         t2[i] = a[i] + t1[i+1]
    else:
        m= a[i]+t1[i+1]
        m = max(m, t0[i+1])
        t0[i] = m
        t1[i] = t0[i+1]
#         t2[i] = a[i] + t1[i+1]
        
print(t0[0])