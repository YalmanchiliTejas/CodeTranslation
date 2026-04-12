N,X =map(int,input().split())
pa =[1]
bu =[1]
for i in range(N-1):
    pa.append(pa[i]*2+1)
    bu.append(bu[i]*2+3)
ans = 0
for i in range(N):
    if X >= bu[N-1-i]*2+2:
        ans += 2*pa[N-1-i]+1
        break
    elif X >= bu[N-1-i]+2:
        ans += pa[N-1-i]+1
        X -= bu[N-1-i]+2
    elif X == bu[N-1-i]+1:
        ans += pa[N-1-i]
        break
    else:
        X -= 1
print(ans)
