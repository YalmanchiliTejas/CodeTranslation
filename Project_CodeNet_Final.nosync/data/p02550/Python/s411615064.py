n,x,m = map(int,input().split())

li = [i%m for i in range(m)]
lin = [i**2%m for i in li]
fra = [0]*m

def calc(num):
    return lin[num]

count = 1
now = x
point = x
kakutei = 0
poilis = [x]

for _ in range(n-1):
    now = calc(now)
    if fra[now] == 1:
        kakutei = poilis.index(now)
        break
    fra[now] = 1
    count += 1
    poilis.append(now)
    point += now

poipoi = poilis[kakutei:]

point2 = sum(poilis[:kakutei])
point -= point2

kai = 0

kai += point2

kai += sum(poipoi)*((n-kakutei)//(count-kakutei))+sum(poipoi[:(n-kakutei)%(count-kakutei)])

print(kai)