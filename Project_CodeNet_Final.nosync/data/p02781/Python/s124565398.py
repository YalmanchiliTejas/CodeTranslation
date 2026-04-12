N = int(input()) # 数字を変数に格納
K = int(input()) # 数字を変数に格納

num = len(str(N))
n = str(N)
List = [[0,0],[0,0],[0,0]]
count = 0

for i in range(num):
    if n[i] != '0':
        List[count][0] = int(n[i])
        List[count][1] = num - i
        count += 1
        if count == 3:
            break
        
result = 0

if K == 1:
    result += List[0][0] + (List[0][1] - 1) * 9
elif K == 2:
    if N <= 10:
        result = 0
    else:
        if List[1][1] != 0:
            result += List[1][0] + (List[1][1] - 1) * 9 # 最高桁数固定
        result += (List[0][0] - 1) * (List[0][1] - 1) * 9 # 最高桁数が上記以外
        result += 9 * 9 * (List[0][1] - 1) * (List[0][1] - 2) / 2 # 最高桁数が0
elif K == 3:
    if N <= 110:
        result = 0
    else:
        if List[2][1] != 0:
            result += List[2][0] + (List[2][1] - 1) * 9 # 最高1桁2桁固定
        if List[1][1] != 0:
            result += (List[1][0] - 1) * (List[1][1] - 1) * 9 # 最高1桁固定2桁が上記以外
        result += 9 * 9 * (List[1][1] - 1) * (List[1][1] - 2) / 2 # 最高1桁固定2桁が0
        result += (List[0][0] - 1) * 9 * 9 * (List[0][1] - 1) * (List[0][1] - 2) / 2 # 最高1桁が上記以外
        result += 9 * 9 * 9 * (List[0][1] - 1) * (List[0][1] - 2) * (List[0][1] - 3) / 3 / 2 # 最高1桁が0

print(int(result))