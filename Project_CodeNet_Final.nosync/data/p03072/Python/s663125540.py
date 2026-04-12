import sys

# 文字の読み込み
N = input()
N = int(N)

st = input().split()
H = [ int(x) for x in st]

# 見える数
# 最初の山は必ず海が見えるので，1からスタート
view = 1

# 一番高い山の高さを記憶
MH = H[0]

# 一番高い山と高さを比較
for i in range(1,N):
    if H[i] >= MH:
        view += 1
        MH = H[i]

print(view)