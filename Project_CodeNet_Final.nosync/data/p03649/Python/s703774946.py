def spaceinput():
    s=input()
    if len(s)==0:
        return False

    return list(map(int,s.split(" ")))


N=int(input())
a=sorted(spaceinput(),reverse=True)

k=0
count=0
N=len(a)
while True:
    #print(a)
    s=int(a[k]/N)
    a[k]-=N*s
    for j in range(N):
        if k!=j:
            a[j]+=s
    count+=s
    if max(a)<N:
        break
    k=(k+1)%N


print(count)
