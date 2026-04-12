N,X = map(int,input().split())

n_sum= X
answer = [0]
def saiki(layer,n_sum,sum_p):
    # print(layer,n_sum,sum_p)
    # if layer == 0:
    #     answer[0] = sum_p
    #     return
    if n_sum == 0:
        answer[0] = sum_p
        return 
    if layer == 1:
        if n_sum == 1:
            answer[0] = sum_p
        elif n_sum == 2:
            answer[0] = sum_p+1
        elif n_sum ==3:
            answer[0] = sum_p+2
        else:
            answer[0] = sum_p+3
        return

    ##現layerの合計を計算
    layer_sum = 2**(layer+2)-3
    ##前のlayerの合計を計算
    pre_layer_sum = 2**(layer+1)-3
    pre_p_sum = 2**(layer)-1
    #もし左側
    if n_sum  < layer_sum //2 +1 :
        # print("left")
        n_sum -= 1
        saiki(layer-1,n_sum,sum_p)
    
    else:
        # print("right")
        n_sum -= (pre_layer_sum+2)
        sum_p += (1+pre_p_sum)
        saiki(layer-1,n_sum,sum_p)

saiki(N,X,0)

print(answer[0])






