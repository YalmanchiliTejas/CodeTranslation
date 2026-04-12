
#"."だけで構成されている列があるかどうかの判定
#--------------------------------------------------------------------------------------------------------------------
def check_column(grid):
    H_temp = len(grid)
    W_temp = len(grid[0])
    column_index = []    
    for i in range(W_temp):
        count_dot_column = 0
        for j in range(H_temp):
            if grid[j][i] == ".":
                count_dot_column += 1
        # print(i)
        # print("grid:{}".format(grid))
        # print("count_dot_column:{}".format(count_dot_column))
        # print("Htemp:{}".format(H_temp))
        if count_dot_column == H_temp:
            column_index.append(i)
    if len(column_index) != 0:
        return True,column_index
    else:
        return False,column_index
#--------------------------------------------------------------------------------------------------------------------

#"."だけで構成されている列を削除
#--------------------------------------------------------------------------------------------------------------------
def del_column(grid,del_column_index):
    H_temp = len(grid)
    # print("del_cplumn_index={}".format(del_column_index))
    for i in range(H_temp):
        del grid[i][del_column_index]
    return grid
#--------------------------------------------------------------------------------------------------------------------




H,W = map(int,input().split())
grid = []
judge = True
# index = []
#"."のみで構成される行を削除
#--------------------------------------------------------------------------------------------------------------------
for i in range(H):
    temp_input = input()
    count_dot = temp_input.count(".")
    if count_dot == W:
        pass
    else:
        grid.append(list(temp_input))
# print(grid)
# print(len(grid))#Hの値が返ってくる
# print(len(grid[0]))#Wの値が返ってくる
#--------------------------------------------------------------------------------------------------------------------
while judge:
    judge,del_column_index = check_column(grid)
    # print(judge)
    if judge:
        # print("value")
        grid = del_column(grid, del_column_index[0])
        # print(del_column_index)
#結果を出力
#--------------------------------------------------------------------------------------------------------------------
# aprint()
for i in range(len(grid)):
    print("".join(grid[i]))
#--------------------------------------------------------------------------------------------------------------------


