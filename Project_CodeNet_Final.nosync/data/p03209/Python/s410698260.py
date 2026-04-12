n,x = map(int,input().split())

tmp_p = 1
tmp_v = 1
p_li = [1]
v_li = [1]
b0_li = [0,1,2,3,3]

for i in range(n):
    tmp_p = tmp_p * 2 + 1
    tmp_v = tmp_v * 2 + 3
    p_li.append(tmp_p)
    v_li.append(tmp_v)

def dfs(x,sou,num):
    #print(x)
    if x == v_li[sou]:
        print(num+p_li[sou])
        return
    elif x == 1:
        print(num)
        return
    elif x <= v_li[sou-1]+1:
        if sou == 2:
            print(num+b0_li[x-2])
            return
        else:
            #print(x-1,sou-1,num)
            dfs(x-1,sou-1,num)
    elif x == v_li[sou-1] + 2:
        print(num+p_li[sou-1]+1)
        return
    elif x <= 2*v_li[sou-1]+2:
        dfs(x-2-v_li[sou-1],sou-1,num+p_li[sou-1]+1)

dfs(x,n,0)
