N = int(input()) 
hotel = list(map(int, input().split())) #入力してint型リストに格納
view = 1

for i in range (1, N, 1):
    judge = 1
    for j in range (0, i, 1):
        if hotel[i] >= hotel[j]:
            pass#何もしない
        else:
            judge = 0
            break
    if judge == 1:
        view += 1

print (view)