N = list(input())
K = int(input())

d = len(N)

def f(j,k):#j桁で0でない桁がk桁ある自然数の個数(最高位0を許す)
    if j < k:
        return 0
    elif k == 0:
        return 1
    elif k == 1:
        return 9*j
    elif k == 2:
        return 81*j*(j-1)//2
    elif k == 3:
        return 729*j*(j-1)*(j-2)//6

b = 0
ans = 0

for i in range(d):
    if b == K:
        break
    else:
        if int(N[i]) != 0:
            ans += f(d-(i+1),K-b) + (int(N[i])-1)*f(d-(i+1),K-b-1)
            b += 1
        else:
            continue

if b == K:
    print(ans+1)
else:
    print(ans)