N=int(input())
A=[]
for i in range(N):
    A.append(int(input()))
A.sort()
me=1
usr=N-2
lenme=A[0]
lenusr=A[N-1]
ans=A[N-1]-A[0]

for i in range(N-2):
    if max([abs(A[me]-lenme),abs(A[me]-lenusr)])>=max([abs(A[usr]-lenme),abs(A[usr]-lenusr)]):
        if abs(A[me]-lenme)>=abs(A[me]-lenusr):
            ans+=abs(A[me]-lenme)
            lenme=A[me]
        else:
            ans+=abs(A[me]-lenusr)
            lenusr=A[me]
        me+=1
    else:
        if abs(A[usr]-lenme)>=abs(A[usr]-lenusr):
            ans+=abs(A[usr]-lenme)
            lenme=A[usr]
        else:
            ans+=abs(A[usr]-lenusr)
            lenusr=A[usr]
        usr-=1
print(ans)