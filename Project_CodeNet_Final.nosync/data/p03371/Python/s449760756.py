A,B,C,X,Y = map(int,input().split())

cost = []
##AとBを独立して買う
cost.append(A*X + B*Y)
##X<Yのとき,ABピザを買う
cost.append(2*C*X+abs(X-Y)*B)
##X>Y
cost.append(2*C*Y+abs(X-Y)*A)
##あまりを作るケース
cost.append(2*C*max(X,Y))

print(min(cost))