N,X,M = map(int,input().split())

l = [X]
a = X
k = 0
for i in range(M):
    if a**2%M not in l:
        l.append(a**2%M)
        a = a**2%M
    else:
        k = l.index(a**2%M)
        break
sum = 0
for i in range(k,len(l)):
    sum += l[i]

ans = 0

ans += ((N-k)//(len(l)-k))*sum

for i in range(min(k,N)):
    ans += l[i]

for i in range(1,(N-k)%(len(l)-k)+1):
    ans += l[k+i-1]

print(ans)
