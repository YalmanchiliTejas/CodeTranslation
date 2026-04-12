n,x,m = map(int,input().split())

cnt = 0
s = set()
L = []
for i in range(n):
    if i == 0:
        x = x%m
    else:
        x = x**2%m
    #print(x)
    if x == 0:
        break
    else:
        cnt += x
        if x not in s:
            s.add(x)
            L.append(x)
        else:
            l = L.index(x)
            restN = n - (i+1)
            restL = len(L)-l
            a = restN%restL
            
            loopcnt = 0
            restcnt = 0
            for j in range(restL):
                loopcnt += L[l+j]
                #print('loop:'+ str(L[l+j]))
                if j > 0 and j <= a:
                    restcnt += L[l+j]
            #print(i,loopcnt,restN,restL,restcnt)
            cnt += loopcnt*(restN//restL) + restcnt
            break
                

print(cnt)
