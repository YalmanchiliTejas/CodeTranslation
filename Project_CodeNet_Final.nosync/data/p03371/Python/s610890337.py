#95c
A,B,C,X,Y = map(int, input().split())

#1≤A,B,C≤5000
#1≤X,Y≤10**5

#愚直解　TLEする。
#minimum_cost = 5000*A + 5000*B +5000*C
#
#for i in range(0,X+1):
#    for j in range(0,Y+1):
#        #残りの必要枚数は?
#        remain = max(X-i,Y-j) 
#        cost = A*i + B*j + C*(remain*2) #残り枚数が多い方の2倍の枚数、ABを買う
#        if minimum_cost > cost:
#            minimum_cost = cost
#
#print(minimum_cost)

minimum_cost = X*A + Y*B + (X+Y)*C

if X>Y:
    for A_pizza in range(0,X+1):
        AB_pizza = (X-A_pizza)*2 #Aピザの残りの必要枚数からABピザの購入枚数が求まる

        if Y - AB_pizza//2 > 0:
            B_pizza = Y - AB_pizza//2 #ABピザの購入枚数からBピザの購入枚数が求まる。ただしマイナスになるなら足りてるので買わない
        else:
            B_pizza = 0

        cost = A*A_pizza + B*B_pizza + C*AB_pizza #残り枚数が多い方の2倍の枚数、ABを買う

        #print(A_pizza,B_pizza,AB_pizza,cost)

        if minimum_cost > cost:
            minimum_cost = cost
            
else:
    for B_pizza in range(0,Y+1):
        AB_pizza = (Y-B_pizza)*2 #Aピザの残りの必要枚数からABピザの購入枚数が求まる

        if X - AB_pizza//2 > 0:
            A_pizza = X - AB_pizza//2 #ABピザの購入枚数からBピザの購入枚数が求まる。ただしマイナスになるなら足りてるので買わない
        else:
            A_pizza = 0

        cost = A*A_pizza + B*B_pizza + C*AB_pizza #残り枚数が多い方の2倍の枚数、ABを買う

        #print(A_pizza,B_pizza,AB_pizza,cost)

        if minimum_cost > cost:
            minimum_cost = cost
            
print(minimum_cost)

#入力の大小関係が異なるパターンに注意