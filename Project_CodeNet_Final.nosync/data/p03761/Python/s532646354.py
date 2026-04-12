n = int(input())
s = [list(input()) for _ in range(n)]

s0 = list(s[0])
s0.sort()
t0 = s0[::1]


for i in range(len(s0)):
    for j in range(1,n):
        if s0[i] in s[j] :
            s[j].remove(s0[i])
        else:
            t0.remove(s0[i])
            break


print(*t0,sep='')
