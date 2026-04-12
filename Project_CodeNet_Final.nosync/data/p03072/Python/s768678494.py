N = int(input())
height_list = [int(i) for i in input().split()]

# 全探索
ans = 0 # 1番目は見えるので
tmp_max = -1
for i in range(N) :
    if(height_list[i] >= tmp_max) :
        tmp_max = height_list[i]
        ans += 1
        

print(ans)

