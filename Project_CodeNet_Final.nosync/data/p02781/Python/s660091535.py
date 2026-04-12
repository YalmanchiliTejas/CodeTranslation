N = list(map(int,list(input())))
K = int(input())
#print(N)

def main(k,p):
    l = len(k)
    x = 9 ** p###先頭桁が0
    for i in range(p):
        x *= max(l - 1 - i,0)
    for i in range(p):
        x //= (i+1)
    y = (k[0] - 1)*(9**(p-1))###先頭桁が1以上k[0]-1以下
    for i in range(p-1):
        y *= max(l - 1 - i,0)
    for i in range(p-1):
        y //= (i+1)
    ##以下, 先頭がk[0]
    i = 1
    while i < l-1 and k[i] == 0 :
        i += 1
    #print("i=",i)
    if p == 1:
        z = 1
    elif i == l-1 and k[i]==0:
        z = 0
    else:
        z = main(k[i:],p-1)
    #print(k,x,y,z)
    return (x+y)+z

if len(N) < K:
    print(0)
else:
    print(main(N,K))