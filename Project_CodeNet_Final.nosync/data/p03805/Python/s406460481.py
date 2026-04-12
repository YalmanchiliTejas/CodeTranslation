N,M= map(int,input().split())
list=[[False for i in range(N)] for j in range(N)]
for i in range (M):
    a,b=map(int,input().split())
    list[a-1][b-1]=True
    list[b-1][a-1]=True
count = 0
flag = [False for i in range(N)]
flag[0]=True

def depth_search (now,flag):
    global count
    tmp_flag = []
    tmp_flag += flag
    tmp_flag[now] = True
    if(False in tmp_flag):
        for i in range(1,N):
            if(list[now][i] and not tmp_flag[i]):
                depth_search(i,tmp_flag)
    else:
        count += 1

for i in range(1,N):
    if(list[0][i]):
        depth_search(i,flag)
print(count)
