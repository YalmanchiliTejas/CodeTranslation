n=int(input())
a=list(input().split(' '))
total=0
S_i=0
for i in range(n-1):
    S_i+=int(a[n-1-i])
    S_i=S_i%(7+10**9)
    total+=S_i*int(a[n-2-i])
    total=total%(7+10**9)
print(total)