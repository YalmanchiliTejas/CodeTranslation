A,B,C,X,Y = map(int,input().split())

ans = 10**9+7

for i in range(max(X,Y)+1):
    AB = i*2
    money = max(0,A*(X-i))+max(0,B*(Y-i))+C*AB
    ans = min(ans,money)
    
print(ans)