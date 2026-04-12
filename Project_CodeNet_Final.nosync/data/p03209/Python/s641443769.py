n,x = map(int,input().split())
burger = [1]
patty = [1]

for i in range(n):
    burger.append(burger[i]*2+3)
    patty.append(patty[i]*2+1)

def f(n,x):
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif x <= 1+burger[n-1]:
        return f(n-1,x-1)
    elif x == 2+burger[n-1]:
        return 1+patty[n-1]
    elif x <= 2+2*burger[n-1]:
        return 1+patty[n-1]+f(n-1,x-2-burger[n-1])
    else:
        return patty[n]

print(f(n,x))