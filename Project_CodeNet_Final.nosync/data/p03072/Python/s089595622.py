N = int(input())
H = list(map(int, input().split(" ")))

cur_max = 0
cnt = 0
for h in H :
    if h >= cur_max :
        cur_max = h
        cnt += 1
        
print(cnt)