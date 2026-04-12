ans = 0
highest_mountain =-1
flag = 0

N = int(input())
h = list(map(int,input().split()))

for i in range(N):
    if (highest_mountain <= h[i]):
        
        highest_mountain =h[i]
        ans +=1
    
        

print(ans) 
