# import sys
# input = sys.stdin.readline

def mp(): return map(int, input().split())
def lmp(): return list(map(int, input().split()))

n,x,m = mp()
u = [0]*m
kaime = [0]*m
a = [x%m]
u[x%m] += 1
kaime[x%m] = 1
t = 0
for i in range(2, n+1):
    x = x**2 % m
    if u[x] == 1:
        t = x
        break
    else:
        u[x] += 1
        a.append(x)
        kaime[x] = i
if n == len(a):
    print(sum(a))
else:
    loop_array = a[kaime[t]-1:]
    loop = (n-kaime[t]+1)//len(loop_array)
    amari = (n-kaime[t]+1)%len(loop_array)
    print(sum(a[:kaime[t]-1])+ loop*sum(loop_array)+sum(loop_array[:amari]))

#sum(sa[:n%len(a)])

