
#f = open("C:/Users/naoki/Desktop/Atcoder/input.txt")
N = int(input())
A = list(map(int, input().split()))
A.insert(0, 0)

select_num = N//2
inf = -10e+100

Dp_f = [[inf] * (3) for _ in range(N+1)]
Dp_s = [[inf] * (3) for _ in range(N+1)]
# 3　次元はそれぞれStart~3つに該当

pre_margin = 0
for i in range(1,N+1):
    Start = (i-1)//2
    End = (i+1)//2
    
    cur_margin = Start
    
    for j in range(Start,End+1):
        Dp_f[i][j-cur_margin] = max(Dp_s[i-1][j-pre_margin], Dp_f[i-1][j-pre_margin])   
        # [0] in 3rd dimension  not chosen at last num
        # must be transfered from [i-1]
    for j in range(Start,End+1):
        if j-1 == 0:
            Dp_s[i][j-cur_margin] = 0 + A[i]
        else:
            Dp_s[i][j-cur_margin] = Dp_f[i-1][j-1-pre_margin]+A[i]
    
    pre_margin = cur_margin
print(max(Dp_f[-1][select_num - cur_margin], Dp_s[-1][select_num - cur_margin]))
