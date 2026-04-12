from collections import defaultdict
n,x,m = list(map(int,input().split()))

def fact(n):
    freq = defaultdict(int)
    if n==0:
        return freq
    while n%2==0:
        freq[2]+=1
        n = n//2
    for i in range(3,int(n**0.5)+1):
        if n%i==0:
            freq[i]+=1
            n = n//i
    if n>1:
        freq[n]+=1
    return freq

can = True
freqx = fact(x)
freqm = fact(m)

for pf in freqm:
    if freqx[pf]==0:
        can = False

if can or n<=m:
    s = x%m
    op = 1
    while op<n:
        rem = x%m
        rem = (rem*rem)%m
        if(rem==0):
            break
        s+=rem
        x = rem
        op+=1
    print(s)
else:
    x = x%m
    lo = [-1 for i in range(m)]
    series = [x]
    lo[x] = 0
    rep = -1
    for i in range(1,m+5):
        rem = (x*x)%m
        if lo[rem]>=0:
            rep = i-lo[rem]
            break
        else:
            series.append(rem)
            lo[rem] = i
        x = rem
    if rep>=0:
        st = len(series)-rep
        n-=st
        mul = n//rep
        ex = n%rep
        s = 0
        for i in range(st):
            s+=series[i]
        for i in range(st,len(series)):
            s+=(mul*series[i])
        for i in range(ex):
            s+=series[st+i]
    print(s)
