A,B,C,X,Y = map(int,input().split())

z = max(X,Y)*2

act_list = []
for i in range(0,z+1,2):
    x = int(X - i*0.5)
    y = int(Y - i*0.5)
    
    if x <= 0:
        x = 0
    if y <= 0:
        y = 0
    act = x * A + y * B + i * C
    act_list.append(act)

print(min(act_list))