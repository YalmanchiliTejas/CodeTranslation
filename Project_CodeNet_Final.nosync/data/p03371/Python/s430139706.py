piza = list(map(int,input().split()))
x = piza[0] * piza[3] + piza[1] * piza[4] #普通に買うパターン
y = piza[2] * 2 * max(piza[3],piza[4])

if piza[3] >= piza[4]:
    z = piza[2] * (2 * piza[4]) + piza[0] * (piza[3] - piza[4])
else:
    z = piza[2] * (2 * piza[3]) + piza[1] * (piza[4] - piza[3])
print(min(x,y,z))
