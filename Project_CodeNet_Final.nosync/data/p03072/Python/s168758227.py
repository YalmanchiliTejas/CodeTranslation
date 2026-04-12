N=int(input())
H=list(map(int,input().split()))
c=1
max_h=H[0]
for n in range(1,N):
    #print(n)
    if max_h <= H[n]:
        max_h=H[n]
        c+=1
print(c)
