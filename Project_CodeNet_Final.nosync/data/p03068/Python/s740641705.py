#標準入力
N = int(input())
S = input()
K = int(input())
#文字列の取得
alt_str = S[K-1]
alt_txt = ""
for i in range(N):
    if S[i] != alt_str:
        alt_txt += '*'
    else:
        alt_txt += alt_str
print(alt_txt)
