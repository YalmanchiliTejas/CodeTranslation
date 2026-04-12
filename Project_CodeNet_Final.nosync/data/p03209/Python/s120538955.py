N, X = map(int, input().split())

# (i)XがLバーガーの半分より上かどうか？を計算
# (ii-i)上の場合: sumに下半分のパティの数を加算。下半分を切り捨てて、L-1バーガに対して、
#        再度X = (X-(Lバーガーの半分の枚数))で(i)から計算
# (ii-ii)下の場合: 上半分を切り捨てて、L-1バーガに対して再度X = (X-(Lバーガーの半分の枚数))で(i)から計算

patty_num_map = {}
size_map = {}
patty_num_map[0] = 1
size_map[0] = 1
for i in range(1, 51):
    patty_num_map[i] = 1+patty_num_map[i-1]*2
    size_map[i] = 3+size_map[i-1]*2

L = N
patty_sum = 0
L1_map = {}
L1_map[0] = 0
L1_map[1] = 0
L1_map[2] = 1
L1_map[3] = 2
L1_map[4] = 3
L1_map[5] = 3
L1_map[6] = 3
for i in range(7, 10000):
    L1_map[i] = 3
while True:
    half = size_map[L]//2+1
    if L < 2:
        patty_sum += L1_map[X]
        break
    if X > half:
        patty_sum += patty_num_map[L-1]+1  # 真ん中のpattyの分
        # X -= half+1  # 一番上のバティの分
        X -= half
        L -= 1
    elif X < half:
        X -= 1  # 一番下のバンの分
        L -= 1
    else:  # ちょうど半分
        patty_sum += patty_num_map[L-1]+1
        break
print(patty_sum)
