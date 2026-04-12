N = int(input())
 
H =  list(map(int, input().split())) 

ans = 1

for i in range(1,N):
    f = True
    for j in range(0,i):
        if H[j] > H[i]:
            f = False
    if f==True:
        ans+=1
    

print(ans)

