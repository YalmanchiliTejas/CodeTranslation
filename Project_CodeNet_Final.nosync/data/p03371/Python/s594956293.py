#「ABピザを買う枚数」で全探索

A,B,C,X,Y = map(int,input().split())

ans = float("inf")

for i in range(0,2*max(X,Y)+1,1):#「ABピザを買う枚数」で全探索
    tmpans = i*C#ABピザの代金

    tmp_x = max(0,X-i//2)
    tmp_y = max(0,Y-i//2)
    tmpans += A*tmp_x
    tmpans += B*tmp_y

    ans = min(ans,tmpans)

print(ans)