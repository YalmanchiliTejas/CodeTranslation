
N = int(input())
yama = input().split()

ans = 1
kj = int(yama[0])

for lop in range(1,N):
    if int(yama[lop]) >= kj :
        ans += 1
        kj = int(yama[lop])
    
 
print(ans)