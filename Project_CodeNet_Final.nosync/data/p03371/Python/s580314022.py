A,B,C,X,Y = map(int,input().split())

ans=10**10
for i in range(0,2*max(X,Y)+1,2):#ABピザを買う枚数を２枚ずらしで全探索
    tmp = max(0,A*(X-0.5*i)) + max(0,B*(Y-0.5*i)) + C*i
    ans=min(ans,tmp)
print(int(ans))